# Assignment 2
# Ananya Agarwal 
# 102083036
# Prective Analysis Using Statistics

library(Peptides)
library(peptider)
library(tools)

#error/exception handling
 tryCatch(
    expr = {
           args = commandArgs()
           
           if(length(args) != 6)
           {
             L = c("Please supply exactly 2 arguments!!!")
             names(L) = paste("Errors while executing the file!!",sep='')
             write.table(L,"Log-102083036.txt",sep=",",row.names=F, col.names=F, append=T)
             stop(L) 
           }
           
           if(!file.exists(args[6]))
           {
             L = c("Input csv File not found!!!")
             names(L) = paste("Errors while executing the file!!",sep='')
             write.table(L,"Log-102083036.txt",sep=",",row.names=F, col.names=F, append=T)
             stop(L)
           }
           
           if (file_ext(args[6]) != "csv")
           {
             L = "The input file you gave does not has csv extension!!!"
             names(L) = paste("Errors while executing the file!!",sep='')
             write.table(L,"Log-102083036.txt",sep=",",row.names=F, col.names=F, append=T)
             stop(L)
           }
        
  
   #Reading the sequence file
   #we have specified that assume empty as NA
   #Reads a file in table format and creates a data frame from it
           
    data <- read.table(args[6], header = TRUE, fill = TRUE, sep=",", na.strings = '') 
    i=0
    for (sequence in data[ ,1]) #1st column (index 1)
    {
      i = i+1
      if(is.na(sequence))
      {
        L = c("Sequence missing in the input file!!!")
        names(L) = paste("Errors while executing the file!!",sep='')
        write.table(L,"Log-102083036.txt",sep=",",row.names=F, col.names=F, append=T)
        print(L) 
        next
      }
      
      cat("\n Reading: ",i,"/", nrow(data))
  
      #nrow() function is used to return the number of rows of the specified matrix
      #cat function in R will combine character values and print them to the screen or save them in a file directly.
  
      #####################Part 1: Single Properties
  
      #feature1: aliphaticIndex
      Aliphatic_index <- aIndex(sequence)
  
      #feature2: bomanIndex
      Boman_index <- boman(sequence)
  
      #feature3: instaIndex
      Insta_index <- instaIndex(sequence)
  
      #feature4: probabilityDetectionPeptide
      probability_detection_peptide <- ppeptide(sequence,libscheme = "NNK", N=10^8)
      #libscheme: library scheme under which neighbors are being calculated.
      # N: number of valid DNA clones investigated
  
      ########Merging of Part1 results
      resultSingle = data.frame(Aliphatic_index, Boman_index, Insta_index, probability_detection_peptide)
  
  
      #####################Part 2: Double Properties
  
      #feature5: hmomentIndex
      hmoment_index_1 <- hmoment(seq = sequence, angle = 100, window=11)
  
      hmoment_index_2 <- hmoment(seq = sequence, angle = 160, window=11)
  
      #feature6: molecularWeight
      molecular_weight_1 <- mw(seq = sequence, monoisotopic = FALSE)
      #monoisotropic: A logical value 'TRUE' or 'FALSE' indicating if monoisotopic weights of amino-acids should be used
  
      molecular_weight_2 <- mw(seq = sequence, monoisotopic = TRUE)
  
      #############Merging of Part2 results
      resultDouble = data.frame(hmoment_index_1, hmoment_index_2, molecular_weight_1, molecular_weight_2)
  
      ###########################Part 3: Multiple Properties
  
      #feature7: peptideCharge
      pkscale = c("Bjellqvist","Dawson","EMBOSS","Lehinger","Murray", "Sillero", "Solomon", "Stryer", "Rodwell")
      feature7 <- c()
  
      for (j in 1:length(pkscale))
      {
        x=charge(seq=sequence, pH=seq(from = 5,to = 9,by = 2), pKscale= "EMBOSS")
        feature7 <- c(feature7,x)
      }
  
      names(feature7) = paste("peptide_charge_",c(1:length(feature7)),sep='')
  
      #feature8: aaComp
      feature8<-as.numeric(unlist(aaComp(sequence)))
      names(feature8)<-paste("aaComp_",c(1:length(feature8)),sep='')
  
      #feature9: isoElectricPoint at 9 pKscale
      pKscale = c("Bjellqvist", "EMBOSS", "Murray", "Sillero", "Solomon", "Stryer", "Lehninger", "Dawson", "Rodwell")
      feature9 <- c()
  
      for (j in 1:length(pKscale))
      {
        x=pI(sequence, pKscale = pKscale[j])
        feature9 <- c(feature9,x)
      }
  
      names(feature9) <- paste("iso_electric_point_",c(1:length(feature9)),sep='')
  
      #feature10: kideraFactors
      feature10 = as.numeric(unlist(kideraFactors(seq = sequence)))
      names(feature10) = paste("kidera_factors_",c(1:length(feature10)),sep='')
      feature10
  
      ##############merging of part 3 results
      resultMultiple = c(feature7, feature8, feature9, feature10)
  
      #merging of all parts and write to file
      finalResult = c(resultSingle,resultDouble,resultMultiple)
  
      length = nchar(sequence)
      names(length) = paste("len",sep='')
      
      tar = data[i,2]
      names(tar) = paste("Target", sep='')
      
      seq = sequence
      names(seq) = paste("Peptide_Sequence", sep='')
      
      ans = c(seq, length, finalResult, tar)
  
      if(i==1){
        write.table(ans,"output-102083036.csv",sep=",",row.names=F, col.names=T, append=F)
      }else{
        write.table(ans,"output-102083036.csv",sep=",", row.names=F, col.names=F, append=T)
      }
    }
    }
 ) 