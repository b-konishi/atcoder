# atcoder

## Educational DP Contest

### A-Frog1
- 1次元DP

### B-Frog2
- 1次元DP

### C-Vacation
- 2次元DPを使用（縦:活動したときの瞬間幸福度 $A(i)$ (3種類:a/b/c), 横:日数 $N(j)$, 幸福度 $H(i,j)$ ）
- $H(i,j)$ <= $N(j-1)$ 日目の $A(i)$ 以外の活動の累積幸福度から最も高いものと、今日の活動 $A(i)$ の和
- 制約： $1\leq N \leq 10^5$, $1 \leq A_i \leq 10^4$
- 愚直計算量: $\mathcal{O}(2^N)$
- DP計算量: $\mathcal{O}(3N)=\mathcal{O}(N)$

### D-Knapsack1
- 2次元DPを使用(縦:商品インデックス $i < N$, 横:重さ $j < W$, 価値 $V(i,j)$ )
- 制約: $1 \leq N \leq 100$, $1 \leq v_i \leq 10^9$ (, $1 \leq W \leq 10^5$ ) であるため、 $1 \leq V(i,j) \leq 10^{11}$ となるため、 $-2 \times 10^9 \sim +2 \times 10^9$ 程度しか扱えない`int`(32bit)ではなく、`int64_t`を使用する
- 計算量: $\mathcal{O}(NW) \sim 10^7$

### E-Knapsnack2
- 問題はDと同様だが、制約条件のデータの範囲が異なる
- 制約: $1 \leq N \leq 100$, $1 \leq v_i \leq 10^3$, $1 \leq W \leq 10^9$
- 問題Dと同様に $N\times W$ のテーブルを組むと最悪 $10^11$ 程度のオーダーとなるため、間に合わない
- 横軸を価値 $V (1 \leq V \leq 10^5)$ に変更することでDPテーブルサイズは $100\times 10^5=10^7$ 程度に抑えられる
- 得られた重さが格納されたテーブルから、制限 $W$ 以内ギリギリの価値 $v$ を取得する
- 横軸のループの際には、以下を基準に条件分けする
  - 自身の価値がj以上である場合、自身(のみ)を加えるか、加えない(前の状態を保持)かを選択できる
  - 自身の価値がj未満である場合、自身だけでは価値が足りない。「自身の重さ+足りない価値の分(i-1)から取得した重さ」と「前の状態を保持したときの重さ」を比較しより小さい方を採用する。
- 計算量: $\mathcal{O}(NV+V)|_{V=Nv_i} = \mathcal{O}(N^2 v_i)$

### F-LCS
- LCS(Longest Common Subsequence: 最長共通部分列)



## ABC270

### A - 1-2-4 Test
- 試験の配点が(2^n)点になっているため、bit演算が可能である
- intでもbit演算は可能

### C - Simple path
- 木構造の表現方法



## ARC149

### A - Repdigit Number
- モジュロ演算
- $1 \leq N \leq 10^5, X < 10^N \leq 10^{10^5} = 10^{100000}$ と非常に大きく全探索は当然不可能
- 一見、桁の大きい方から見ていき打ち切る方法が思いつくが、計算量削減のため、漸化式によって小さい方から進める必要がある。
- 漸化式は剰余情報のみ引き継げばよい
- 計算量 $\mathcal{O}(N) \leq 10^5$


## Tips

### 基本C++テンプレート
`template.cpp`を参照

### コンテスト環境構築用Linuxコマンド
コマンド定義は`atcoder.sh`ファイル参照。

```shell
cp atcoder.sh ~/command/atcoder
chmod 777 ~/command/atcoder
echo "export PATH=$HOME/command:$PATH" >> ~/.zshrc
echo "alias atcoder='source atcoder'" >> ~/.zshrc # shellで実行したcdをターミナルに反映させる
```

```
NAME
  atcoder - create an environment and execute automatically for AtCoder contests

SYNOPSIS
  atcoder -t [DIRECTORY]
  atcoder -e FILE
  atcoder -m DIRECTORY
  atcoder -g [STRING]
  atcoder -h

DESCRIPTION
  -t  create an environment by using tmux
  -e  execute a cpp-file automatically in case that the file is updated by constant monitoring    
  -m  make a directory and some cpp-files, that are required for the contest
  -g  execute git commands for commit and push
  -h  display this help and exit
```


### コード提出用Vimコマンド
デバッグ用のコードやコメント、空行を削除するために、`.vimrc`に記載する

```
nnoremap <C-y><C-y> :g/\v\/\/<BAR>^\s*$/d<ENTER>ggVGyu:nohlsearch<ENTER><C-o><C-o><C-o>
```






