# ft_printf - V0.5.6

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
    - Renamed get_flags() to analyse()
	- Decomposition of analyse() to respect the norme
	- Add get_flags(), get_min_width(), get_precision()

    ————————————————————————————————————
		Cur State:
	————————————————————————————————————
    - %s, %c, %d, %x, %u, %% Seems OK with basics flags "+-0 "
	- Remain 6 bugs for %p and 1 for %s
	- Tester Result (skipping bonus) [1742/1749]


	————————————————————————————————————
    	Known Bugs:
	————————————————————————————————————
    - Try to gest %p, miss begining of address
    - %p doesn't display beginning of address
    - Need to find a way to make one function from functions gest_precision and no_precision
    - No errors gest
