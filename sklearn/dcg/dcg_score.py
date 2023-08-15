import numpy as np

from sklearn.metrics import dcg_score, ndcg_score

y_true = np.asarray([[0.006977, 0.073222, 0.009765, 0.010187, 0.023717, 0.043478, 0.020787, 0.000000, 0.021429, 0.017811, 0.000000, 0.016980]])
y_score = np.asarray([[0, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11]])

foo = dcg_score(y_true, y_score, k = 10)
print(foo)

y_score2 = np.asarray([[1111, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0]])
bar = dcg_score(y_true, y_score2, k = 10)
print(bar)

y_trues = np.flip(np.sort(y_true), axis = 1)
print(y_trues)
y_true2 = np.delete(y_trues, [0], axis = 1)
y_score2 = np.delete(y_score, [0], axis = 1)
foo = ndcg_score(y_trues, y_score, k = 10)
print(foo)
bar = ndcg_score(y_true2, y_score2, k = 10)
print(bar)
