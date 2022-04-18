#Ananya Agarwal
#3COE14
#102083036
#Assignment 3

#checking the version of the pycaret after importing it 
from pycaret.utils import version
version()

#importing all the libraries
import pandas as pd
from pycaret.classification import*
import os
import sys

#reading the input file 
df = pd.read_csv(sys.argv[1])

#######accuracy without normalization
setup(data = df, target='Target', silent=True)
cm = compare_models()
noNorm_output = pull()
noNormAcc = noNorm_output[["Accuracy"]]

########Model performance using "Normalization"
#######getting accuracy after normalization

a = setup(data=df, target='Target', normalize = True, normalize_method = 'zscore', silent=True)
cm = compare_models()
a_output = pull()
a_acc = a_output[["Accuracy"]]

b = setup(data=df, target='Target', normalize = True, normalize_method = 'minmax', silent=True)
cm = compare_models()
b_output = pull()
b_acc = b_output[["Accuracy"]]

c = setup(data=df, target='Target', normalize = True, normalize_method = 'maxabs', silent=True)
cm = compare_models()
c_output = pull()
c_acc = c_output[["Accuracy"]]

d = setup(data=df, target='Target', normalize = True, normalize_method = 'robust', silent=True)
cm = compare_models()
d_output = pull()
d_acc = d_output[["Accuracy"]]

#index column
i1 = list(noNormAcc.index)
index1 = pd.DataFrame({'mod':i1},index=i1)
#index and data both is saved thus within a row data in fine

#other columns
ans1 = [index1, noNormAcc, a_acc, b_acc, c_acc, d_acc]
d1 = pd.concat(ans1,axis=1)

#heading
heading1 = ["Model","Accuracy without normalization","Accuracy with norm(z-score)","Accuracy with norm(min-max)","Accuracy with norm(maxabs)","Accuracy with norm(robust)"]
fin_ans1 = d1.set_axis(heading1, axis=1)
#print(fin_ans1)

###downloading dataset to the local system
fin_ans1.to_csv("output-102083036-Normalization.csv", index=False)

########Model performance using "Feature Selection"
#######getting accuracy after feature selection
e = setup(data=df, target='Target', feature_selection = True, feature_selection_method = 'classic', feature_selection_threshold = 0.2, silent=True)
cm = compare_models()
e_output = pull()
e_acc = e_output[["Accuracy"]]

f = setup(data=df, target='Target', feature_selection = True, feature_selection_method = 'classic', feature_selection_threshold = 0.5, silent=True)
cm = compare_models()
f_output = pull()
f_acc = f_output[["Accuracy"]]

g = setup(data=df, target='Target', feature_selection = True, feature_selection_method = 'boruta', feature_selection_threshold = 0.2, silent=True)
cm = compare_models()
g_output = pull()
g_acc = g_output[["Accuracy"]]

h = setup(data=df, target='Target', feature_selection = True, feature_selection_method = 'boruta', feature_selection_threshold = 0.5, silent=True)
cm = compare_models()
h_output = pull()
h_acc = h_output[["Accuracy"]]

#index column
i2 = list(noNormAcc.index)
index2 = pd.DataFrame({'mod':i2},index=i2)
#index and data both is saved thus within a row data in fine

#other columns
ans2 = [index2, noNormAcc, e_acc, f_acc, g_acc, h_acc]
d2 = pd.concat(ans1,axis=1)

#heading
heading2 = ["Model","Accuracy without FeatureSelec.","Accuracy with FeatureSelec(classic=0.2)","Accuracy with FeatureSelec(classic=0.5)","Accuracy with FeatureSelec(boruta=0.2)","Accuracy with FeatureSelec(boruta=0.5)"]
fin_ans2 = d2.set_axis(heading2, axis=1)
#print(fin_ans2)


###downloading dataset to the local system
fin_ans2.to_csv("output-102083036-FeatureSelection.csv", index=False)

########Model performance using "Outlier Removal"
#######getting accuracy after Outlier Removal
i = setup(data=df, target='Target', remove_outliers = True, outliers_threshold = 0.02, silent=True)
cm = compare_models()
i_output = pull()
i_acc = i_output[["Accuracy"]]

j = setup(data=df, target='Target', remove_outliers = True, outliers_threshold = 0.04, silent=True)
cm = compare_models()
j_output = pull()
j_acc = j_output[["Accuracy"]]

k = setup(data=df, target='Target', remove_outliers = True, outliers_threshold = 0.06, silent=True)
cm = compare_models()
k_output = pull()
k_acc = k_output[["Accuracy"]]

l = setup(data=df, target='Target', remove_outliers = True, outliers_threshold = 0.08, silent=True)
cm = compare_models()
l_output = pull()
l_acc = l_output[["Accuracy"]]

#index column
i3 = list(noNormAcc.index)
index3 = pd.DataFrame({'mod':i3},index=i3)
#index and data both is saved thus within a row data in fine

#other columns
ans3 = [index3, noNormAcc, i_acc, j_acc, k_acc, l_acc]
d3 = pd.concat(ans1,axis=1)

#heading
heading3 = ["Model","Accuracy without OutlierRemoval","Accuracy with OutlierRem(threshold=0.02)","Accuracy with OutlierRem(threshold=0.04)","Accuracy with OutlierRem(threshold=0.06)","Accuracy with OutlierRem. (threshold=0.08)"]
fin_ans3 = d3.set_axis(heading3, axis=1)
#print(fin_ans3)

###downloading dataset to the local system
fin_ans3.to_csv("output-102083036-OutlierRemoval.csv", index=False)

########Model performance using "PCA"
#######getting accuracy after PCA
m = setup(data=df, target='Target', pca = True, pca_method = 'linear', silent=True)
cm = compare_models()
m_output = pull()
m_acc = m_output[["Accuracy"]]

n = setup(data=df, target='Target', pca = True, pca_method = 'kernel', silent=True)
cm = compare_models()
n_output = pull()
n_acc = n_output[["Accuracy"]]

o = setup(data=df, target='Target', pca = True, pca_method = 'incremental', silent=True)
cm = compare_models()
o_output = pull()
o_acc = o_output[["Accuracy"]]

#index column
i4 = list(noNormAcc.index)
index4 = pd.DataFrame({'mod':i4},index=i4)
#index and data both is saved thus within a row data in fine

#other columns
ans4 = [index4, noNormAcc, m_acc, n_acc, o_acc]
d4 = pd.concat(ans4,axis=1)

#heading
heading4 = ["Model","Accuracy without PCA","Accuracy with PCA(Method=linear)","Accuracy with PCA (Method=kernel)","Accuracy with PCA(Method=incremental)"]
fin_ans4 = d4.set_axis(heading4, axis=1)
#print(fin_ans4)

###downloading dataset to the local system
fin_ans4.to_csv("output-102083036-PCA.csv", index=False)

#graphs and tables
setup(data=df, target='Target', silent=True)
best = compare_models()

########Graph for confusion Matrix by best model
plot_model(best, plot='confusion_matrix', save = True)
os.rename('Confusion Matrix.png','output-102083036-ConfusionMatrix.png')

########Graph for Learning Curve by best model
plot_model(best, plot='learning', save = True)
os.rename('Learning Curve.png','output-102083036-LearningCurve.png')

########Graph for AUC Curve by best model
plot_model(best, plot='auc', save = True)
os.rename('AUC.png','output-102083036-AUC.png')

########Graph for Decision Boundary by best model
plot_model(best, plot='boundary', save = True)
os.rename('Decision Boundary.png','output-102083036-DecisionBoundary.png')

########Graph for Feature Importance by best model
plot_model(best, plot='feature', save = True)
os.rename('Feature Importance.png','output-102083036-FeatureImportance.png')