# ft_printf - V0.5.4

-> make - Compile only

-> make launch - Compile changes & launch

-> make test - Compile changes & launch @Chinimala tester

Units tests in main.c 

or 

run "sh test-printf/test-printf.sh" for @Chinimala tester
(More details: https://github.com/Chinimala/42-tests)


    ————————————————————————————————————
    	Changes:
    ————————————————————————————————————
    - Better result for %d

    ————————————————————————————————————
		Cur State:
	————————————————————————————————————
    - %s, %c, %d, %x, %u, %% Seems OK with basics flags "+-0 "
	- Tester Result (skipping bonus) [1682/1749] (+12)


	————————————————————————————————————
    	Known Bugs:
	————————————————————————————————————
    - Try to gest %p, miss begining of address
    - %p doesn't display beginning of address
    - Need to find a way to make one function from functions gest_precision and no_precision
    - No errors gest
