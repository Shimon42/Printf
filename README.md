# ft_printf - V0.5.8

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
	- Add %n gest

    ————————————————————————————————————
		Cur State:
	————————————————————————————————————
    - %s, %c, %d, %i, %p, %xX, %u, %%, %n Seems OK with all flags "# +-0.*"
	- Remain 1 bug for ("%.s", 42) -> SEGFAULT
	- Brain.h not normed (func ptr)
	- Tester Result (skipping bonus) [1748/1749] (+6)


	————————————————————————————————————
    	Known Bugs:
	————————————————————————————————————
    - Try to gest %p, miss begining of address
    - %p doesn't display beginning of address
    - Need to find a way to make one function from functions gest_precision and no_precision
    - No errors gest
