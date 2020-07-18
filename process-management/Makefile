include ../shared-makefiles/Makefile.gitignore
include ../shared-makefiles/Makefile.help

.PHONY: run
run:
	./a.out

.PHONY: clean
clean:
	command -v ./a.out && rm ./a.out

readelf: ## プログラムのエントリポイントが見えたりする
	readelf -h /bin/sleep | grep "Entry point address"
	readelf -S /bin/sleep
