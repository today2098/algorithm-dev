## 概要

実行時に法が決まる「Modint構造体」．

インスタンスを生成する前に法とする自然数を設定する．

```cpp
DynamicModint<0>::set_modulus(17);
DynamicModint<1>::set_modulus(23);

DynamicModint<0> a = 28;
DynamicModint<1> b = 28;

cout << a << " " << b << endl;  // 11 5
```
