#!/bin/zsh

readonly ATCODER_DIR="${HOME}/workspace_atcoder"
option=""
arg=""

# オプションと引数を分けて取り込む(オプションと引数が1つずつの場合のみ想定)
while (( $# > 0 ))
do
  case $1 in
    -t)
      option=$1
      ;;
    -e)
      option=$1
      ;;
    -m)
      option=$1
      ;;
    -g)
      option=$1
      ;;
    -h)
      option=$1
      ;;
    -*)
      echo "Error: invalid option"
      return
      ;;
    *)
      arg=$1
      ;;
  esac
  shift
done


if [[ "$option" = "-t" ]]; then # -t: tmux環境構築
  if [[ -n "$arg" ]]; then # argが空ではないとき
    cd ${ATCODER_DIR}/${arg}
  else
    cd ${ATCODER_DIR}
  fi
  tmux split-window -v
  tmux split-window -h vim ${ATCODER_DIR}/input.txt
  tmux resize-pane -D 15
  tmux resize-pane -R 15
  tmux select-pane -t 1
  tmux select-pane -t 0

elif [[ "$option" = "-e" ]]; then # -e: コードの監視・自動実行
  if [[ -n "$arg" ]]; then # argが空ではないとき

    INTERVAL=1 # 監視間隔, 秒で指定
    last=`ls --full-time ${arg} | awk '{print $6"-"$7}'`
    while true; do
      sleep $INTERVAL
      current=`ls --full-time ${arg} | awk '{print $6"-"$7}'`
      if [ $last != $current ]; then
        echo ""
        echo "updated: $current"
        echo "[Executing ...]"
        last=$current
        g++ ${arg} && a.out
        echo "[Done]"
      fi
    done

  else
    echo "Error: requires an argument for a file name"
    return
  fi

elif [[ "$option" = "-m" ]]; then # -m: ディレクトリとファイルの生成
  if [[ -n "$arg" ]]; then # argが空ではないとき
    mkdir ${arg}
    for i in {a..g}.cpp
    do
      cp ${ATCODER_DIR}/template.cpp ${arg}/$i
    done
    echo "Created a directory and some cpp-files"
  else
    echo "Error: requires an argument for a dir name"
    return
  fi

elif [[ "$option" = "-g" ]]; then # -g: git管理
  cp ${HOME}/command/atcoder ${ATCODER_DIR}/atcoder.sh
  chmod 664 ${ATCODER_DIR}/atcoder.sh
  git add .
  if [[ -n "$arg" ]]; then # argが空ではないとき
    git commit -m "add ${arg}"
  else
    git commit -m "update"
  fi
  git push origin master

elif [[ "$option" = "-h" ]]; then # -h: ヘルプ
  echo ""
  echo "[option]"
  echo "-t: arrange tmux-panes"
  echo "-e: monitor a file given as argument and execute it"
  echo "-m: create a directory and some cpp-files"
  echo "-g: execute git commands for commit and push"
  echo ""
  return
else
  echo "Error: requires an option and an argument"
  return
fi

