# ft_printf - V0.5.3

-> make - Compile only

-> make launch - Compile changed & launch

Units tests in main.c 

or 

run "sh test-printf/test-printf.sh" for @Chinimala tester
(More details: https://github.com/Chinimala/42-tests)


    ————————————————————————————————————
    	Changes:
    ————————————————————————————————————
    - Fix bad results for p->precision == 0 with %d
	- Add Libft->ft_putnbr (long)
	- Skip tester's test after "[K - Tests with f]"

    ————————————————————————————————————
		Cur State:
	————————————————————————————————————
    - %s, %c, %d, %x, %u, %% Seems OK with flags "+-*0 .#"
	- Tester Result (skipping bonus) [1670/1749]

	————————————————————————————————————
    	Known Bugs:
	————————————————————————————————————
    - Try to gest %p, miss begining of address
    - %p doesn't display beginning of address
    - Need to find a way to make one function from functions gest_precision and no_precision
    - No errors gest
