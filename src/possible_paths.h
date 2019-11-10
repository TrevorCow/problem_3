long possiblePathsRecursive(int M, int N) {
    if (M == 0 || N == 0) {
        return 0;
    }

    if (M + N == 2) {
        return 1;
    }

    return possiblePathsRecursive(M - 1, N) + possiblePathsRecursive(M, N - 1);
}

long possiblePathsIterative(int M, int N) {
    if (M == 0 || N == 0) {
        return 0;
    }

    long pathCount[M][N];

    for (int i = 0; i < M; i++) {
        pathCount[i][0] = 1;
    }
    for (int j = 0; j < N; j++) {
        pathCount[0][j] = 1;
    }

    for (int i = 1; i < M; i++) {
        for (int j = 1; j < N; j++) {
            pathCount[i][j] = pathCount[i - 1][j] + pathCount[i][j - 1];
        }
    }
    return pathCount[M - 1][N - 1];
}
