include ../shared-makefiles/Makefile.gitignore
include ../shared-makefiles/Makefile.help

.PHONY: run
run:
	./a.out

.PHONY: strace
strace: a.out ## straceは1行 = 1システムコール
	@strace -T -o hello.c.log ./a.out && grep "write(" hello.c.log
	@strace -T -o hello.py.log python3 hello.py && grep "write(" hello.py.log

.PHONY: clean
clean:
	command -v ./a.out && rm ./a.out
	rm *.log

################################################################################
# userモード: %user, %nice
################################################################################
.PHONY: sar
sar: ## システム統計情報(sysstat)、Ctrl+cで平均が出される
	sar -P ALL 1

################################################################################
# 色々なプログラムが内部的には標準Cライブラリ(libc)が使用されていることがわかる
################################################################################
ldd: ## プログラムがどんなライブラリをリンクしているか
	ldd /bin/echo
	ldd /usr/bin/python3
	ldd ./a.out
