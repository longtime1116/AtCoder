# AtCoder Problems
https://kenkoooo.com/atcoder/?user=longtime&rivals=&kind=category

# 準備

```bash
$brew install gcc-5
$ln -s /usr/local/bin/gcc-5 /usr/local/bin/gcc
$ln -s /usr/local/bin/g++-5 /usr/local/bin/g++
```

# 教訓

* ABC、C問題がわからなくてもまずD問題を見てみるべし。自分のなかの難易度が世間の難易度と一致しないケースもあるので、Dのほうが簡単に解けることもある。
* 簡単なケースでは正常な動きをするが大きな入力で正しい答えがでないときは int で overflow している可能性を意識する。(10^9 + 7 で割った余り、みたいなときとか)

# テクニック
* 2^n の組み合わせは bit により表現できる。
* DP っぽいときの頭の使い方
  * dp[i][j] とかに何を入れるのかを考える。
  * それはメモリ/速度的になんとかなるレベル？
  * 前の状態から今の状態を一意に決定できる？できないならそれはそのやり方ではできない。
  * 3要素
    * 状態
    * 遷移(漸化式)
    * 埋める順番

# 参考

* pair の vector(sort, 二分探索含む)
  * ABC032 d
* map 操作
  * ABC032 d
* トポロジカルソート
  * EDPC g
  * ABC139 e


# 使用アルゴリズム

* 01ナップザック問題
  * ABC032 D
  * ABC015 D
* 桁DP
  * tdpc E
  * ABC129 E
* 最長増加部分列
  * ABC006 D
* ロリハ+二分探索、Z-Algorithm
  * ABC141 E
* combination の計算(パスカルの三角形)
  * ABC110 D
* 素因数分解の取得
  * ABC110 D
* しゃくとり
  * ABC130 D
* ベルマンフォード
  * ABC061 D
* 二分探索の実装(ライブラリ使わないもの)
  * ABC063 D
