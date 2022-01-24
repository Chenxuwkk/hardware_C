cc=gcc
exec=main
obj=main.o fun.o
flags=-Wall
$(exec):$(obj)
	$(cc) $^ -o $@ $(flags)
%.o:%.c
	$(cc) -c $< -o $@ $(flags)

clean:
	rm $(obj) $(exec)