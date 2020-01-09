# ft_printf - V0.6

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
	- Fixed ("%.s", 42)
	- Fixed %p bad display
	- All Normed

    ————————————————————————————————————
		Cur State:
	————————————————————————————————————
    - %s, %c, %d, %i, %p, %xX, %u, %%, %n Seems OK with all flags "# +-0.*"
	- Tester Result: [1030/1749]
		Skipping bonus: [1749/1749]

	————————————————————————————————————
    	Known Bugs:
	————————————————————————————————————
    - Need to find a way to make one function from functions gest_precision and no_precision
    - No errors gest
