#!/bin/zsh

WORKSPACE_NAME="workspace_atcoder"
ATCODER_DIR="${HOME}/${WORKSPACE_NAME}"
option=""
arg=""

# オプションと引数を分けて取り込む(オプションと引数が1つずつの場合のみ想定)
# 引数を必要としないオプションはここで処理&終了
while (( $# > 0 ))
do
  case $1 in
    -t | --tmux)
      option="tmux"
      ;;
    -e | --execute)
      option="execute"
      ;;
    -m | --mkdir)
      option="mkdir"
      ;;
    -g | --git)
      option="git"
      ;;
    -h | --help)
      echo ""
      echo "[option]"
      echo "-t: arrange tmux-panes"
      echo "-e: monitor a file given as argument and execute it"
      echo "-m: create a directory and some cpp-files"
      echo "-g: execute git commands for commit and push"
      echo ""
      return
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


if [ "$option" = "tmux" ]; then # -t: tmux環境構築

  if [ -n "$arg" ]; then # argが空ではないとき
    cd ${ATCODER_DIR}/${arg}
  elif [ `pwd | sed -e "s|${WORKSPACE_NAME}||" | wc -m` -eq `pwd | wc -m` ]; then # 元々workspace内にいないとき
    cd ${ATCODER_DIR}
  fi
  tmux split-window -v
  tmux split-window -h vim ${ATCODER_DIR}/input.txt
  tmux resize-pane -D 15
  tmux resize-pane -R 15
  tmux select-pane -t 1
  tmux select-pane -t 0

elif [ "$option" = "execute" ]; then # -e: コードの監視・自動実行
  if [ -n "$arg" ]; then # argが空ではないとき

    INTERVAL=1 # 監視間隔, 秒で指定
    cpp_last=`ls --full-time ${arg} | awk '{print $6"-"$7}'`
    input_last=`ls --full-time ${ATCODER_DIR}/input.txt | awk '{print $6"-"$7}'`
    while true; do
      sleep $INTERVAL
      cpp_current=`ls --full-time ${arg} | awk '{print $6"-"$7}'`
      input_current=`ls --full-time ${ATCODER_DIR}/input.txt | awk '{print $6"-"$7}'`
      if [ "$cpp_last" != "$cpp_current" -o "$input_last" != "$input_current" ]; then
        echo ""
        echo "updated: $cpp_current"
        echo "[Executing ...]"
        cpp_last=$cpp_current
        input_last=$input_current
        g++ ${arg} && a.out
        echo "[Done]"
      fi
    done

  else
    echo "Error: requires an argument for a file name"
    return
  fi

elif [ "$option" = "mkdir" ]; then # -m: ディレクトリとファイルの生成
  if [ -n "$arg" ]; then # argが空ではないとき
    mkdir ${arg} || return
    cd ${arg}
    for i in {a..g}.cpp
    do
      cp ${ATCODER_DIR}/template.cpp $i
    done
    echo "Created a directory and some cpp-files"
  else
    echo "Error: requires an argument for a dir name"
    return
  fi

elif [ "$option" = "git" ]; then # -g: git管理
  git pull origin master
  find ${ATCODER_DIR}/ -name "a.out" | xargs rm
  cp ${HOME}/command/atcoder ${ATCODER_DIR}/atcoder.sh
  chmod 664 ${ATCODER_DIR}/atcoder.sh
  git add .
  if [ -n "$arg" ]; then # argが空ではないとき
    git commit -m "add ${arg}"
  else
    git commit -m "update"
  fi
  git push origin master

else
  echo "Error: requires an option and an argument"
  return
fi

