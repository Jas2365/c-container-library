cxx = gcc
cflags =

src_dir = src
out_dir = out

inc = -Iinc -Iinc/strings
srcs = $(wildcard $(src_dir)/*.c) $(wildcard $(src_dir)/**/*.c)

objs = $(patsubst $(src_dir)/%.c, $(out_dir)/%.o, $(srcs))


target = out/main.exe

all: $(target) run

#  linking 
$(target): $(objs)
	@echo Linking $@ ...
	@$(cxx) $(objs) -o $(target)

# compilation
$(out_dir)/%.o : $(src_dir)/%.c
	@if not exist "$(dir $@)" mkdir $(subst /,\, $(dir $@))"
	@echo Compiling $< ...
	@$(cxx) $(inc) -c $< -o $@

run:
	@echo  ---- Running Project ---- 
	@./$(target)
	@echo  ---- Ending  Project ---- 
	
clean:
	@echo ---- Cleaning up ----
	@if exist "$(out_dir)" rd /s /q $(out_dir)