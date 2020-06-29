#! /bin/sh

DIR=/home/class/j5/imageSystem/.send/R2

sel=1
dname=""

while [ "$sel" != "0" ]
do
  flag=0
  echo
  echo "******************************************"
  echo "  1  提出用ディレクトリ一覧"
  echo "  2  提出先ディレクトリの設定"
  echo "  3  現在ディレクトリのファイル一覧"
  echo "  4  ファイルを提出する"
  echo "  5  提出したファイル一覧"
  echo "  6  提出したファイルの内容確認"
  echo "  7  間違って提出したファイルを削除"
  echo "  0  終了"
  echo
  echo "どれを実行しますか? 数値を入力して下さい．入力ミスをしたら，Ctrl + u"
  echo -n "(提出先ディレクトリ："

  if [ "$dname" = "" ]; then
    echo -n "未設定) "
  else
    echo -n "$dname) "
  fi

  read sel
  echo

  if [ "$sel" = "1" ]; then
    flag=1
    echo "#################################################################"
    echo "提出先ディレクトリ名 一覧"
    echo 
    ls -vACF --color=auto $DIR/$USER | more
    echo "#################################################################"
    echo
  fi

  if [ "$sel" = "2" ]; then
    flag=1
    echo -n "提出先ディレクトリ名 = "
    read dname
    if [ ! -d $DIR/$USER/$dname ]; then
      echo
      echo "$dname は存在しません．"
      echo
      sleep 1
      dname=""
    fi
  fi 

  if [ "$sel" = "3" ]; then
    flag=1
    if [ "$dname" = "" ]; then
      echo "まずはメニューの2番で提出先のディレクトリを設定して下さい．"
      sleep 1
    else
      echo "#################################################################"
      echo "現在ディレクトリのファイル一覧"
      echo
      ls -vCF --color=auto | more
      echo "#################################################################"
      echo
      echo
    fi
  fi

  if [ "$sel" = "4" ]; then
    flag=1
    if [ "$dname" = "" ]; then
      echo "まずはメニューの2番で提出先のディレクトリを設定して下さい．"
      sleep 1
    else
      echo "提出先ディレクトリ名 = $dname"
      echo -n "提出ファイル名 = "
      read fname
  
      if [ ! -e $fname ]; then
        echo "$fname は存在しません．"
        sleep 1
      else
        cp $fname $DIR/$USER/$dname/ >/dev/null 2>&1
	if [ $? -eq 0 ]; then
          chmod -R o-rwx $DIR/$USER/$dname/$fname
          echo
          echo "**************************************************"
          echo "$fname を提出しました．"
          echo "**************************************************"
          echo
	else
	  echo
          echo "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
          echo "提出に失敗しました．"
          echo "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
        fi
        sleep 1
      fi
    fi
  fi

  if [ "$sel" = "5" ]; then
    flag=1
    if [ "$dname" = "" ]; then
      echo "まずはメニューの2番で提出先のディレクトリを設定して下さい．"
      sleep 1
    else
      echo "#################################################################"
      echo "提出先ディレクトリ名 = $dname"
      echo
      ls -vACF --color=auto $DIR/$USER/$dname | more
      echo "#################################################################"
      echo
    fi
  fi
   
  if [ "$sel" = "6" ]; then
    flag=1
    if [ "$dname" = "" ]; then
      echo "まずはメニューの2番で提出先のディレクトリを設定して下さい．"
      sleep 1
    else
      echo "提出先ディレクトリ名 = $dname"
      echo -n "確認ファイル名 = "
      read fname

      if [ -f $DIR/$USER/$dname/$fname ]; then
        less $DIR/$USER/$dname/$fname
      else
        echo "$fname は提出されていません．"
        sleep 1
      fi
    fi
  fi

  if [ "$sel" = "7" ]; then
    flag=1
    if [ "$dname" = "" ]; then
      echo "まずはメニューの2番で提出先のディレクトリを設定して下さい．"
      sleep 1
    else
      echo "提出先ディレクトリ名 = $dname"
      echo -n "削除ファイル名 = "
      read fname

      if [ -f $DIR/$USER/$dname/$fname ]; then
        echo "提出先($dname)の$fname を削除します．"
        echo -n "よろしいですか? (y/n) "
        read yn1
        if [ "$yn1" = "y" ]; then
          echo -n "本当に削除しますか? (y/n) "
	  read yn2
          if [ "$yn2" = "y" ]; then
            echo 
            echo "提出先($dname)の$fname を削除すると復活できません．"
            echo -n "今ならまだ間に合います．削除を「やめますか?」(y/n) "
	    read yn3
            if [ "$yn3" = "n" ]; then
              rm -f -- $DIR/$USER/$dname/$fname
              echo 
              echo "$fname を削除しました．"
              echo "注意！間違いがないか、一覧で確認しておきましょう．"
              sleep 1
            else
              echo "削除を思いとどまりました．"
              sleep 1
            fi
          fi
        fi
      else
        echo "$fname は提出されていません．"
        sleep 1
      fi
    fi
  fi


  ## Input Error
  if [ $flag -eq 0 -a "$sel" != "0" ]; then
    echo "数値を入力して下さい．"
    sleep 1
  fi
done

## EOF
