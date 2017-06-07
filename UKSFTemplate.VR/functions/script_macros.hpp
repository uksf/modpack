#define PREFIX uksf
#define ADDON DOUBLES(PREFIX,COMPONENT)

#define QUOTE(var) #var
#define DOUBLES(var1,var2) ##var1##_##var2
#define TRIPLES(var1,var2,var3) ##var1##_##var2##_##var3

#define FORMAT_1(STR,ARG1) format[STR, ARG1]
#define FORMAT_2(STR,ARG1,ARG2) format[STR, ARG1, ARG2]
#define FORMAT_3(STR,ARG1,ARG2,ARG3) format[STR, ARG1, ARG2, ARG3]

#define LOG_SYS_FORMAT(LEVEL,MESSAGE) format ['[%1] (%2) %3: %4', toUpper 'PREFIX', 'COMPONENT', LEVEL, MESSAGE]
#define LOG_SYS(LEVEL,MESSAGE) diag_log text LOG_SYS_FORMAT(LEVEL,MESSAGE)

#define INFO(MESSAGE) LOG_SYS('INFO',MESSAGE)
#define INFO_1(MESSAGE,ARG1) INFO(FORMAT_1(MESSAGE,ARG1))
#define INFO_2(MESSAGE,ARG1,ARG2) INFO(FORMAT_2(MESSAGE,ARG1,ARG2))
#define INFO_3(MESSAGE,ARG1,ARG2,ARG3) INFO(FORMAT_3(MESSAGE,ARG1,ARG2,ARG3))

#define GVAR(var)  DOUBLES(ADDON,var)
#define EGVAR(var1,var2) TRIPLES(PREFIX,var1,var2)
#define QGVAR(var) QUOTE(GVAR(var))
#define QEGVAR(var1,var2) QUOTE(EGVAR(var1,var2))
#define FUNC(var1) TRIPLES(ADDON,fnc,var1)
#define QFUNC(var1) QUOTE(FUNC(var1))

