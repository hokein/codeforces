## A. 简单模拟

## B. 枚举

枚举sum，然后计算出数字，判断一下是否合法即可。

注意，要用long long, 计算过程中会溢出；
还有注意范围10^9


## C. 线段树

每次选取最左边的最小值开始成段更新，更新m次后，mini值就是结果。