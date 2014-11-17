SUBDIRS :=list hello
all:modules
.PHONY:all
modules:
	for n in $(SUBDIRS)
	do
		exit=make --directory=$$n
		if[ $exit ="1" ];then
			exit 1
		fi
	done
.PHONY:modules
clean:
	for n in $(SUBDIRS)
	do make --directory=$$n clean
	done
.PHONY:clean
