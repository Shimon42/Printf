# ft_printf - V0.5

-> make - Compile only

-> make launch - Compile changed & launch

Tests in main.c




————————————————————————————————————
Changes:
————————————————————————————————————
- Fix bad results with negative numbers and no precision (%d and %i)
- Add gest precision for %%
- rm "long ret" in libft->ft_abs()

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


