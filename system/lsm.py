
import numpy as np
import re

if __name__ == "__main__":

    path = '/home/yu_pippi/programming/Python/LSM/data/lsmPractice_train.csv'

    with open(path, mode="r") as data_file:
        # reshape data
        data_list = [i.strip() for i in data_file.readlines()]
        if re.fullmatch(r'[.*].csv', path) != 'None':
            data_list = [i.replace(',', ' ') for i in data_list]
        data_list = [i.split() for i in data_list]
        data_list = np.array(data_list)
        data_num = 0
        for i in data_list:
            data_num += 1

    # declare variable for saving error
    error_num = 0.0
    error_diff = 0.0
    error_diff_old = 0.0

    # dimension of expression
    N = 0

    # define lamda
    lamda = 0.0

    ans_mat = ans_mat_old = np.array(np.zeros((N + 1, 1)))
    while True:
        # initialize matrix by index
        array1 = np.array(np.zeros((N + 1, N + 1)))
        array2 = np.array(np.zeros((N + 1, 1)))

        if error_diff > error_diff_old and error_diff_old != 0:
            print('Minimum error = %lf' % error_diff_old)
            print('--- answer matrix ---')
            print(ans_mat_old)
            print('Expression : y =', end = '')
            for i in range(N - 1):
                print(' + (%lf)*(x ** %d)' % (float(ans_mat_old[i][0]), ((N - 1) - 1) - i), end = '')
            print('')
            break
        else:
            #save error
            error_diff_old = error_diff
            error_diff = 0.0
            ans_mat_old = ans_mat

        # calculate matrix
        for i in range(N + 1):
            for j in range(N + 1):
                for k in range(data_num):
                    array1[i][j] += pow(float(data_list[k][0]), int((2 * N) - i - j))

        for i in range(N + 1):
            for j in range(data_num):
                array2[i][0] += pow(float(data_list[j][0]), int(N - i)) * float(data_list[j][1])

        array1_inv = np.linalg.inv(array1)
        ans_mat = np.dot(array1_inv, array2)

        regularization = 0.0
        # calculate error sum
        for i in range(data_num):
            for j in range(N + 1):
                error_num += float(ans_mat[j][0]) * pow(float(data_list[i][0]), int(N - j))
                regularization += pow(float(ans_mat[j][0]), 2)
            error_diff += (pow(float(data_list[i][1]) - error_num, 2) + lamda + regularization) / 2
            error_num = 0

        N += 1
        print('error = %lf' % error_diff)