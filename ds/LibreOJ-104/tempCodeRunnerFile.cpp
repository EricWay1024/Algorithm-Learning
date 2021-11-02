    int n = read();
    while (n--) {
        int opt = read(), val = read();
        if (opt == 1) {
            insert(val);
        } else if (opt == 2) {
            Remove(val);
        } else if (opt == 3) {
            printf("%d\n", getRankByVal(val) - 1);
        } else if (opt == 4) {
            printf("%d\n", getValByRank(val + 1));
        } else if (opt == 5) {
            printf("%d\n", getPreNext(val, 0)->val);
        } else if (opt == 6) {
            printf("%d\n", getPreNext(val, 1)->val);
        }
        // bb;
    }