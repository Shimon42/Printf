# ft_printf - V0.6.4

-> make - Compile libftprintf.a

    ————————————————————————————————————
    	Changes:
    ————————————————————————————————————
	- Fix bad results when ("%X %x"), uppercase was set in the chained list and never reset
	- Fix bad results with ("%.p", NULL)
	- Add bonus rule in Makefile

    ————————————————————————————————————
		Cur State:
	————————————————————————————————————
	- 100% working (without bonus %e, %f, %g and ' flag)
    - %s, %c, %d, %i, %p, %xX, %u, %%, %n Seems OK with all flags "# +-0.*"
	- Tester Result: [1034/1749]
		Skipping bonus: [1749/1749]
	- No Leaks

	————————————————————————————————————
    	Known Bugs:
	————————————————————————————————————
    - Need to find a way to make one function from functions gest_precision and no_precision
    - Not all errors gest
	- Need to RM useless vars in t_param
	- Need to copy params_list elem to cur_param istead of using it directly (%xX bug source)
