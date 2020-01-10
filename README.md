# ft_printf - V0.6.2

-> make - Compile libftprintf.a

    ————————————————————————————————————
    	Changes:
    ————————————————————————————————————
	- Add gest when bad param or no param

    ————————————————————————————————————
		Cur State:
	————————————————————————————————————
	- 100% working without bonus (%e, %f, %g and ' flag)
    - %s, %c, %d, %i, %p, %xX, %u, %%, %n Seems OK with all flags "# +-0.*"
	- Tester Result: [1034/1749]
		Skipping bonus: [1749/1749]
	- No Leaks

	————————————————————————————————————
    	Known Bugs:
	————————————————————————————————————
    - Need to find a way to make one function from functions gest_precision and no_precision
    - Not all errors gest
