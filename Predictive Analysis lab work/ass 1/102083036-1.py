try:
    
    #importing all the necessary libraries
    import pandas as pd
    import sys
    import warnings
    warnings.filterwarnings("ignore")
    
    #incorrect number of parameters
    if len(sys.argv) != 2:
        raise Exception
        
except:
    print("You have given wrong number of inputs!!!")
    L = ["You have given wrong number of inputs!!!"]
    f = open("102083036-log.txt", "a")
    f.writelines(L)
    f.close()
    
else:
    
    #wrong type of input file
    try:
        if "csv" not in sys.argv[1]:
            raise Exception
            
    except:
        print("The input file you gave is not csv file!!!")
        L = ["The input file you gave is not csv file!!!"]
        f = open("102083036-log.txt", "a")
        f.writelines(L)
        f.close()
        
    else:
        
        try:
            #read original file
            df = pd.read_csv(sys.argv[1])
              
        except:
            print("File does not exist!!!")
            L = ["File does not exist!!!"]
            f = open("102083036-log.txt", "a")
            f.writelines(L)
            f.close()
            
        else:
            #input file containing not exactly 3 number of inputs  
            try:
                if len(df.columns) != 3:
                    raise Exception
              
            except:
                print('Number of columns in the input file is not three!!!')
                L = ["Number of columns in the input file is not three!!!"]
                f = open("102083036-log.txt", "a")
                f.writelines(L)
                f.close()
                
            else:

                #preprocessing data i.e. removing all non numeric data such as missing values, nan, X and -
                #and putting the nion numeric data to the log file
                df_x = df[df['Marks'] == 'X']
                df_x.to_csv("102083036-log.txt",index=False, sep =' ',mode='a')

                df_nan = df[df['Marks'] == 'NAN']
                df_nan.to_csv("102083036-log.txt",index=False, sep =' ',mode='a', header=False)

                rows_miss = df[df.isnull().any(axis=1)]
                rows_miss.to_csv("102083036-log.txt",index=False, sep =' ',mode='a', header=False, na_rep = ' ')

                df_hyphen = df[df['Marks'] == '-']
                df_hyphen.to_csv("102083036-log.txt",index=False, sep =' ',mode='a', header=False)

                #df_preprocessed DataFrame conatins only the numeric data
                df_preprocessed = df.drop(list(df_nan.index) + list(df_x.index) + list(rows_miss.index) + list(df_hyphen.index))

                #creating 5 different DataFrames for the 5 submission values
                #P1
                df_P1 = df_preprocessed[df_preprocessed['Submission'] == 'P1']
                df_P1.drop('Submission', inplace =True, axis=1)
                df_P1.rename(columns = {'Marks': 'P1'}, inplace = True)
                df_P1.set_index('RollNumber', inplace = True)

                #P2
                df_P2 = df_preprocessed[df_preprocessed['Submission'] == 'P2']
                df_P2.drop('Submission', inplace =True, axis=1)
                df_P2.rename(columns = {'Marks': 'P2'}, inplace = True)
                df_P2.set_index('RollNumber', inplace = True)

                #P3
                df_P3 = df_preprocessed[df_preprocessed['Submission'] == 'P3']
                df_P3.drop('Submission', inplace =True, axis=1)
                df_P3.rename(columns = {'Marks': 'P3'}, inplace = True)
                df_P3.set_index('RollNumber', inplace = True)

                #P4
                df_P4 = df_preprocessed[df_preprocessed['Submission'] == 'P4']
                df_P4.drop('Submission', inplace =True, axis=1)
                df_P4.rename(columns = {'Marks': 'P4'}, inplace = True)
                df_P4.drop_duplicates(subset ="RollNumber",keep = 'first', inplace = True)
                df_P4.set_index('RollNumber', inplace = True)

                #P5
                df_P5 = df_preprocessed[df_preprocessed['Submission'] == 'P5']
                df_P5.drop('Submission', inplace =True, axis=1)
                df_P5.rename(columns = {'Marks': 'P5'}, inplace = True)
                df_P5.set_index('RollNumber', inplace = True)

                #result dataframe contains only the numeric data in each Submission column
                #result dataframe has RollNumber as index and 5 submission values as 5 different columns
                result = pd.concat([df_P1, df_P2, df_P3, df_P4, df_P5], ignore_index=False, sort=True, axis=1)

                #count the total number of missing values
                totMiss = result.isnull().sum().sum()

                #replacing nan values with 0
                result.fillna(0, inplace=True)

                #typecasting values of the dataframe to an integer
                result[['P1','P2','P3','P4','P5']] = result[['P1','P2','P3','P4','P5']].astype(int)

                #putting all the data to the output.csv file
                name = '102083036-output.csv'
                result.to_csv(name)

                #adding Total-of-all column in result dataframe
                result["Total-of-all"] = result.sum(axis=1)

                #calculating data for the statistics file
                nonNumeric = len(list(df_nan.index) + list(df_x.index) + list(rows_miss.index) + list(df_hyphen.index))

                missValue = totMiss - nonNumeric

                meanList = result[['P1','P2','P3','P4','P5','Total-of-all']].mean()
                meanList.to_list()
                
                medianList = result[['P1','P2','P3','P4','P5','Total-of-all']].median()
                medianList.to_frame()

                modedf = result[['P1','P2','P3','P4','P5','Total-of-all']].mode().transpose()

                minList = result[['P1','P2','P3','P4','P5','Total-of-all']].min()
                minList.to_frame()

                maxList = result[['P1','P2','P3','P4','P5','Total-of-all']].max()
                maxList.to_frame()

                sd = result[['P1','P2','P3','P4','P5','Total-of-all']].std()
                sd.to_frame()

                #appending all the calculated stats in the statsdf
                statsdf = pd.concat([meanList, medianList, modedf, minList, maxList, sd], ignore_index=True, sort=True, axis=1)
                statsdf.rename(columns = {0:'MEAN',1:'MEDIAN', 2:'MODE', 3:'MIN', 4:'MAX', 5:'STANDARD_DEVIATION'}, inplace=True)
                statsdf.transpose()
  
                #putting the calculations into statistics.txt file
                name1 = '102083036-statistics.txt'
                statsdf.to_csv(name1)
              
                L = ['Number of missing values are:' +str(missValue),'\nNumber of non numeric values are:'+str(nonNumeric)]
                f1 = open("102083036-statistics.txt", "a")
                f1.writelines(L)
                f1.close()

