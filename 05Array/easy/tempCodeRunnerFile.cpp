int missingNumber(vector<int>&a, int N) {

    // Outer loop that runs from 1 to N: Correct array
    for (int i = 1; i <= N; i++) {

        // flag variable to check
        //if an element exists
        int flag = 0;

        //Search the element using linear search: Given array
        for (int j = 0; j < N - 1; j++) {
            if (a[j] == i) {

                // i is present in the array:
                flag = 1;
                break;
            }
        }

        // if element is not in array then the if stmt in second loop wont execute and flag will be 0
        //  i th element in correct array is the missing one

        if (flag == 0) return i;
    }

    // The following line will never execute.
    // It is just to avoid warnings.
    return -1;
}
