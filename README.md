# Libft - ft_printf - V0.5

-> make - Compile only

-> make launch - Compile changed & launch

Units tests in main.c 

or 

run "sh test-printf/test-printf.sh" for @Chinimala tester
(More details: https://github.com/Chinimala/42-tests)




————————————————————————————————————

Changes:

————————————————————————————————————
- Merged ft_printf & Libft
- Libft re-organized!

————————————————————————————————————

Cur State:

————————————————————————————————————
- %s, %c, %d, %x, %u Seems OK with flags "+-*0 .#"

Bugs:
- Bad results when %% at end of string
- Try to gest %p, miss begining of address
- %p doesn't display beginning of address
- Need to find a way to make one function from functions gest_precision and no_precision
- No errors gest


