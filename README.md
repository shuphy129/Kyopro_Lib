# 競プロライブラリ

## 使い方

```
git clone https://github.com/shuphy129/Kyopro_Lib.git
```

**`Kyopro_Lib/library/z_template`** の **`A.cpp`** をコピペして使う。

main関数に以下を記述してコンパイルが通ればOK。
コンパイラのバージョンが古いとエラーになる。

```cpp
int main(){
    int a, b;
    IN(a, b); // 2変数入力
    OUT(a, b, a + b); // 出力
    return 0;
}
```
