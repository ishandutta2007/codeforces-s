#include <bits/stdc++.h>
using namespace std;
const int Mod=1'000'000'007;
/*
Coded by 
The most beautiful girl in the world
@@@@@@@@@@##&|;!!!!!!!!!!||||||||%%%%%$$$$$$$$$$$$%%$$$&&&&&&&&&$$&&&&&&&&&@@@&%||||||$&&&&@&%;'```'`':!||%&@@@@#@&&&&&@@@&&$$$&&@@&$$$&@@@@@@@@@@@@@#@@@@@@@@@@#@@@@@#@@@@@@@@@@##$
@@@@@@@@@####$!;!!!!!!!!!||||||||%%%%%%%%%%%%%%%$$$$&&&&&&&&&&&&&&&&&&&&@@@@@@&%|||||!:'`'!$&&&&&&%:''!|||$&&&@@@@@@&&&&&@@@&$$$&&@&&$&&@@@@@@@@@@@@@@@@@@@@@@@@##@@@@#@@@@@@@@@@#@%
@@@@@@@@@####@|;!!!!!!!!!|||||||%%%%%%%%%%%%%$$$$$$$$$$&&&&&&&&&&&&&&&@@@@@@@@&%|;:'''''``````'!$&&&@@&|:;%$$&&&@@@@@&&&&&@@@&$$$&&@@@@@@@@@@@@@@@@@@@@@@@#@@@@@#@@@@@#@@@@#@@@@##@%
@@@@@@@@####@@&|;!!!!!!!!|||||||%%%%%%%%%%%%%%$$$$$$$$&&&&&&&&&&&$$$&&@@@@@@@@@@&$|;'''''````````'':!$&&&$%%%%$$&@@@@@&&&&&@@@@&&&@@#@@@@@@@@@@@@@@@@@@@@@@@@@@@#@@@@@@@@@@#@@@@#@@%
@@@@@@@#####@@@$!;!!!!!!|||||||%%%$$$$$%%%%%%%%%$$$$$$$&&&&&&&&&$$$$&&@@@@@@@@$%$&@@&&&@&$%;:':;:''`````'|%%%%%%$$&@@@@@&&&&@@#@@@@@@#@@@@@@@@@@@@@@@@#@@@@@@@@@#@@@@@@@@@@@@@@#@@@%
@@@@@@#####@$%%%$$$%%%||%%||||%%%%$%%$$$$$%%%%%%%$$$$&&&&&&&&&$$$$$$&&@@@@@@@&$;'''''':!%&&&&&&@@&%;'```:$&&%%%%%$$$&@@@@&&&&@@@@@@@@@#@@@@@##@@@@@@@@#@@@@@@@@@@@@@@#@@@@@@@@@#@@@%
$&@@@@######&&&&&$%%%%|%|||||||%%%%%$$$$$$$$$$$$$&&&&&&&&&&&&&&&&$$$$&&@@@@@@&$!''''''````````:!|$&&&&&&&$&&&$%%%%$$$&&@@@&&&&&@@@@&@@@@@@@@@#@@@@@@@@#@@@@@&&&@@@@@@@@@@@@@@@#@@@@$
$$$&@######@&&&&&&|!!!!!|||||||%%$$$$$$$$$$$$$$$&&&&&$$&&&&&&&&&&&&$$&&&@@@@@@&%;::''````````'':'``....`;|%$&&&$%%$$$$$&@@@&&&&&@@@@@@@@#@@@@@#@@@@@@@@@@@@@@&&@&&&&&&&&&@@@@@@@@@@$
$$$&@#####@&$$&&@#&|!!!!!|||||||%%%$$$$%%%%%$$$$$$$&&&&&&&&&&&&@@@@@&&&&&&@@@@@@@@@@@&&&&&&&&@@@@&&$$%||||%%%$$&&&$$$$$$$&@@@&&&&&@@@@@@@#@@@@@@@@@@@@@@@@@@@@&&@&&&&&&&&@@@@@@@@@#$
$$&@######@&$&@##@&$|!!!!|||||||%%%%%%%%%%%%%$$$$&&&&&&&&&&&&&&&&&&&&$$&&&&&&@@&|'`````````':::;;;;;;!|%%%%%%%%$&@@&$$$$$$$&@@&&&&&@@@@@@@@@@@@@@@@@@@@#@@@@@@@@@&&&&&&&&&@@@@@@@#@%
$&@######@&&&@##@$$$$|!!!||||||||%%%%%%%%%%%%$$$$&&&&&&&&&&&&&&&&&&&&$&&&&&&&&@@$!:::'':::::::::::::''``.:%%$$$$$$&@@@&$$$$$&@@@&&&&@@@@@@@@@@@@#@@@@@@@@@@#@@@@#@@@@@@&&&@@@@@@@@@%
$&@######@&&@#@&$$$$&$|!!!||||||||%%%%%%%%%$$$$$&&&&&&&&&&&&&&&&&&&$$$&&&&&&&&&&&%;::::::::::::':''':'':::%&$$$$$$$$&&@@&$$$$$&@@@&&&&@@@@@@@@@@@@@@@@@@#@@@@@@@@@@@@@@@@@@@@@@@@@@%
&@#######@@@#@&$$$$$&&$|!!|||||||||%%%%%%$$$$$$$$$&&&&&&&&&&&&&&&$$$$$&&&&&&&&&&&$!''::::'''::;!|%%$&&@@@@&&@@$$%%$$$$&&@&&$$$$&@@@&&&&@@@@@@#@@@@@@@@@@@@@@@@@#@@@@@@@@@@@@@@@@@@@%
############&$$$$$$$&&&$|!!||||||||%%%%%%$$$$$$$$$$$$$$&&&&&$$$$$$$$$$&&&&&&&&&&&&@@@&&&&&&&@@@@@@&&&$$%|!;%@@@@&$$$$$$$$&@@&$$$$&@@@&&&@@@@@@@@@#@@@@@@#@@#@@@@@@@@@@@@@@@@@@@@@@@$
########@&$$$$$$$$$&&&&&$|!!||||||%%%%%%$$$$$$$$$$$$$$$$$$$$$$$$$$$$$&&@@&&&&&&&&&&&&&&$$$$$$$$$$&&&$$%!;:::|$&@@@@&$$$$$$$&@@&$$$&@@@&&&@@@@@@@@##@@@@@@@@@@@@#@@@@@@@@@@@@@@@@@@@$
########@$%%%$$$$$$&&&&&&&%!||||%%%$$$%%%%%%%%%%%%%%%%%%%%%%%$$$$$&&&&&&&&&&@@@&&&&&&&&&&&&$$$$$$$$$$$$$&&%!!$$$$&@@@@&$$$$$$&@@@&&&&@@@&&@@@@@@@##@@@@@#@@@@@@@@@@@@@@@@@@@@@@@@@@%
#######@&$$$$$$$$$$$$&$|!||%%%%||%%%%%%%%%%%%%%%%%$$$$$$&$$$$$&&&&&&&&@@@@&&&&&&&&&&&&&&&&&&&$$&&$$$$$$$$$&&&$&@&$$$&@@@&$$$$$$&@@@@&&@@@@&@@@@@@###@@@@@@@@@@@@@@@@@@@@@@@@#@@@@#@%
#######@$$$$$$%$$$$$$$&&$||||%%%%%%$$$$$$$$$$$$$$$$$$$$$$$&&&&&&&&&&@@&&&&&&&&&&&&$$$$$$&&&&$$$$$$$$$$$$$$$$$$&@@@@&$$$&@@@&$$$$&&&@@@&@@@@&&@@@@@###@@@@#@@@@@#@@@@@@@@@@@#@@@@#@@$
#######&$$$$$$$$$$&$$$$$&&&&&$%||%%%%%%$$$$$$$$$$$$$$$$$&&&&&&&&&&&@&&&&&&&&&&&&$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$&&@@@&$$$&@@@&$$&&&@@@@@@#@@@@@@@@##@@@@#@@@@@@@@@@@@@#@@@@@@##@##$
######@$$$$$$$$$$$$$$$$$$&&&&&&$||%%%%%%%$$$$$$$$$$$$$&&&&&&&&&@@&&&&&&&&&&&&&&$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$&@@@@@&&$&&@@@&&&&&@@@@@##@@@@@@@##@@@###@@@@@@@@@@@@@@#@@@#@#@@%
######&$$$$$$$$$$$$$$$$$&&&&&&&&$%|%%%%%%%$$$$$$$$$$&&&&&&&&&&@&&@@&&&&&&&&&&$$$$$$$$$$$$$$$$$$$$$$$&$$$$$$$$$$$$$$$$&@@@@@@&&&&&@@@&&&&@@@@@#@@@@@###@@@##@@@@@@@@@@@@@@#@@@####@#$
#####@$$$$$$$$$$$$$$$$$$$&&&&&&&&&%%%%%%%%%$$$$$$$$&&&&&&&&&&&&&&&&&&&&&&&&$$$$$$$$$$$$$$$$$$$$$$$$$$&$$$$$$$$$$$$$$$$$&&&@@@@@&&&&@@@@@@@@@@@@#@@@@###@@@$%%%%%%%%%%%%%$&@@#######$
#####@&$%$$$$$$$$$$$$$$$$$$&&&&&&&&$%%%%%%%%%%$$$$&&&&&&&&&&&&&&&&$$$$$$$$$$$$$$$$$$$$$$$$$$%$$$$$$$$$%%$$$$$$$$%%$$$$$%&@&&&&@@@@@&&@@@@@&&@@@@#@@@@###@&%%%%%%%%%%%%%%%%%&@##@##@%
####@@@@&$$$$$$$$$$$$$$$$$$&&&&&&&&&&%%%%%%%%%%$$&@&&&&$&&&$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$||$$$$$$$$%%$$$$$|%$$$$$$$%%$&@@@&&&@@@@@@@@@@@@&@@@@@@@@##@&%%%%%%%%%%%%%%%%%%%$@@@@@%
####@@@@@@&$%$$$$$$$$$$$$$$$$$&&&&&&&&$%%%%%%%$&&&&&$$$$$$&$$$$$$$$$$$$$$$$$$$$$$$%%$$$%%%%|!|||$$$$%!|%%%$$&$$$$$$$$$$%%%$&@#@@@@&&@@@@@@@@@@@@@@##@@@@#@@@&$$%%%%%%%%|%%%%%|$@@@@$
###@@@@@@@@$$$%$$$$$$$$$$$$$&&&&&&&&&&&&%%%%%&&&&&$%%%$$&&&$$$$$$$$$%%%$$|%$$$%%%$%%|%%!;!||!!||%$$$$$$$%%$&$$&&$$$$$$$$$$%%$@@#@@@@@@&&@@@@@@@@#@@###@@@########@@$%%%%%%%|%%$&@##$
##@@@@@@@@@&$$$&$$$$$$$$$$$$$$$&&&&&&&&&&&%%%$&%|%%%%%$%%$$%%%%%%$$$%%%$$||%%%$$$$$%%%%%$$$$$%!!|%&&$$$$%|$$$$$$&$$$$$$$$$$$%$$&@@@@@@@@@@@@@@@##@@@@##@@####@@#######&%%%%%%%$@###$
#@@@@@@@@@@&&$$&$$$$$$$$$$$$$$$&&&&&&$||%%%$$%!;!;!|%%%%$%!||||%%%$$$||%$%%%%%%$$$$%$$%%%%$%$$$$||$&&$$&%|%$$$$$$$&$%%$%|%$$$$%$%$@@@@@@##@@@@@@@@@@########@##@@@######&$$&@@@@@##$
@$$&@@@@@@@&&$$$$$$$$$$$$$$$$$$&&&$&&&&$$&$$%!|%%%%%%%%%%||%%%%%%%%$$||%$$$$%%%%$$$%%$$%%%%%%%$$%|%&&$$&$%%$$$$$$$&&$%%&&&&$$$$$$$||$@@@@@@@@@@@@@@@@@@@####@@@@##@@@#@@@@@@@@@@@@@%
&$%%$$&&&$$$$$$$$$$$$$$$$$$$$$$$$$$&&&&&&&&|!|%%%%|%%%%%%$%%%%||||%$$%|%$&&$%%%%$$$$%$$%%%%$$$$$%|$&&&$&$$$&$&$$$$&&&$%$&&&$$&&&&&$%!!|$&@@@@@@@@@@@@@@@@###@@@@@@@@@@@@@@@@@@@@@@@%
$$%$$$$$$$$$$$$$$$$$$$$$$$$$$$$&&&$&&&&&&$|!|||%%|%%%%%%$$%%%%||||%$$%%%$&&$%%%$$&&&$$$$$$$$$$$$$%%&&&&&$$&&$&$$&&&&&&&&&&&&&&&&&&&&$|!!!!$&@@@@@@@@@@@#####@######@##@@&@@@@@@@@@@$
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$&&&&&&$|!|||%$%%%%%%%$$$$%%%||||%$$%%%$&&$$%%$&&&&&$$$$$$$$$$$$%%&&&&&$$&&$&$$&&&&&&&&&&&&&&&&&&&&&&%!!!!|&&&@@@@@@#########@########@@##########$
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$&&&&&$&$%|!||%$$%%$%%%%$$$$$%%|||||$$$&$$&$$$%$&&&&&&$$$$$%$$$$$$%$&&&&&&&&&&&$$&&&&&&&&&&&&&&@@&&&&&@@$|!$@&||||%&@#@@####@########@@@@@@@#@&&@@##$
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$&&&$$&$%|!||%$$%%%%%%%$$$%$$%%||||%$&&&&&&$$$$$$&&&&&$%$$$%%$$$$$%$&&&&&&&&$$$$$&&&&&&&&&&&&&&@@@&&@@@@@&@@&|||||||||%&@###############@@@@@@##@@@@%
%$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$&$&&$$$$%!!|%$$$%%%%%%$$$$%$$$%||||$&&$$&&$$$$$$$&&&$&$%%$%%%%%%$$%$$$&&&&&$$$$$$&&&&&&$&&&&&&&&&&&&&&&@@@@&||||||||||||$@#####@@@########@@@@@###@@$
%%%%%%%%$$$$$$$$$$$$$$$$$$$$$$$$$&&%%&%!!||%$$%%$$%%$$$$%%$$%%|!|%&&$%%&&$%%%%$$$&$|%$||$%%%%%%$$$$$$&&&&$$$$$$&&&&&&$$$&&&&&&&&&&@@&&&@@@&&%|||||||||%&@@##@$$@@@@########@@@@@@##$
;:''':;!|%%$$$$$$$$$$$$$$&&&&&&&&%%&&$!!|%%%%%%%$$$$$$$%%%$%%%|||$$&%!%&$%%%%|%%%&%!|$||%%%%%%%$$$$%%$&&$$$$$$$&&&&&&$$$$&&&&&&&&&&&&&&@@@@&&%|||||||%@@@@#@%|&#$||||%&@@@@@@@@@@@@$
.....  .`;|%%$$$$$$$$$$$&&&&&&$%%$&&$!;|%%|||%%$$&&&&$$%%$$%%%%%%%&%!;|$$%||||%%%$|;!%||$%$$$$$%%%%||$&$%%%$$$$&&&&&&$$$$&&&&&&&&&&&&&@@@@@@&&%|||||$@@@##&%|%@@%||||||||||&@@@@@@@%
........  `;|%$$$&&&&&&&&&&&$%$&&&&$|!|%%|!!|||$&$&&&$$%%%%%||||%$$|;;|%%|||||%$&&$|!|!!%%%%%%|!!|%!%$$%||%$&$&&&&&&&$$$$&&&&&&&&&&&&@@@@@@@@&&%|||$@@@##@$||$#&|||||||||||&#$|||||!
...    ..  `;|%$$$$&&&&&&$%$$&&&&&&||%%$||!!||$&$$$$$$%%%%%%||||%$%!:!!!%%$$$%%%%|!;;;;;!!!!!;;;||!%&%|%%%$&&$&&&&&&&$$$$&&&&&&&&&&&@@@@@@@@@&&$||$@##@@@%||%&@$||||||||||%&@$|||||!
       ..  .'!|%$$&&&&&&&&&&&&&&&&||$$&%||!||%&&$$$$$$%%$%||||||%|!;:;;;|%|!!!!!|!|$$&&&&$$$%!!!!;|&&$%%%$&$$$$%||&@&$$$$&&&&&&&&&@@@@@@@@@@@@&$|%@@@@#@%|||$@&%||||||||||%@@%|||||!
       ... .';|%$$&&&&&&&&&&&&&&&%%&$&&%|||||%&&$$$$$$%%$%%%||||%!;:::::::'':;!|%%%%$&@&&$%|!|%|;!$&$%|%%$$$$&$|!|$@@&$$$&@@@@@@@@@@@@@@@@@@@@&$$@@@#@&%|||%&#$|||||||||||$@&%|||||!
    ....   .:!|%$$&&&&&&&&&&&&&&$$&&&&$|||||%$@&$$&$$&&&$%|%%%%|;::''''''````'!!!;'`'%@&%|!::!;;!$$||%%%$&$$$$|!!|%&@@&&&&@@@@@@@@@@@@@@@@@@@@&&@@@@#@%||||$@@$|||||||||||$#&||||||!
     ..   .';!|%$$$&&&&&&&&&&&&$$&&&&&$$%||%%&@&$$&$$$$%|!;;;;:::'`````````````````';;:;!;'::::;%$|||!!|$$$%$%||||$@@@&&&@@@@@@@@@@@@@@@@@&&@&&&&&&@@@$%%||&#&%||||||||||%&#$||||||!
        .`:!!!|$$&&&&&&&&&&&&&&&&&&&&&&&$%$$$&@&&$&&$$|!|%$$$$%|;''``````````````':;!!!;::''':;!$%|$$%%$$$$$$%!!%&@@@@@@@@@@@@@@@@@@@@@@@@&&&&@&$$&@@@@@@@@@#&%||||||||||%@@$||||||!
;:''`'':;!!!!|%$$&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&$&&&&&$|!%%%%$&$$|;'``````````````''''''''::::;|$&$$$%%$$%%$$$&@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&@&$$$&&&@@@@@@@@@@@@@@&$%|||$@@$||||||!
|!;;;!!!!!!|%$$$&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%!:;|!||!!:'''``````````````''''''''':;;|$$$$$%%$%$$$&&&&&@@@@@@@@@@@@@@@@@@@@@@@@&&&@&$$$&&&&&@@@@@##@@@@@&&@@@@@@#@&%|||||!
%|!!!!!!||%$$$&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@&&&&&&$$$!';;;:'```''`````````````````'''''';;:|$$$$$$$$%$$$&@&&&&@@@#@@@@@@@@@@@@@@@@@@@&&@&$$$$$$$&&&@@@@##@%;''|&@@@@@@@#@@@@@@@%
&$%%%%%%$$$$&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@&&&@&&&$$$%;``'''``':'``````````````````'''':::;|$$$$$$$%$$$$&&&&&&@@@##@@@@@@@@@@@@@@@@@@&@&$$$&&&$$$&&&@@@@|:''':%@@@@@@@#@@@@@@@@%
@@&$$$$$&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@&&@@&&&$$$$%:``````';:'```...`````````````'''':;|$$$$$$%%$$$$&&&&&&&@@##@@#######@@#@@@@@@#@&$$&&&&&$%$$&&@@%:'::'!&@@@@&@@@@@@@@@@@%
##@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@&&&&&&&$$%:``````':;:```..``````````````''':;|$$$$$$%%$$$&&&&&&&@@@####################@&$$&&$$$$$$$|;|&$!''':;$&&&&&&@@@@@@@@@@@%
##@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&$&@&$&&&$&&&&&%'``````.``````....```````````'`'';|$&$$$%$$$$$$&&&&&@@@@@##################@$$$&&$$$$$|:':;%&$;''''|&&&&&&&&@@@@@@@@@@%
##@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&$%$&@@$$$$$&&&&&@@!````````.......````````````''`'':!%$&&&$$&&&&&&&&&&@@@#@@##############@@&$$$$&$$$$$$|:''|&&|''''!$&&&&&&@@@@@@@@@@@@%
##@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&|;%&$&@$$$$$$&&&&&@@&;..``..........````````````''``'';%$&&&&&&&&&&&&&&@@@@@##@############@@@$$$$&$!|$$$$!:':%@%:``':%&&@@@@@@@@@@@@@@@@@%
##@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&$!!$&&$&&$|!|%$$$&&&@@@@$:.........``'''``':;:'`````````':!%$&&&&&&&@&&&&&@@@@@@@#@@#########@@@&$$$%!!$$$$$%;'';$&!``':%@@@@@@@@@@@@@@@@@@@&%
##@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&|;%&&&&$%%$%!|%%$$$$&&@@@@@$;`.....`...````````````````````';|$&&&&&&&&@@@&&&@###@@@@#@&&##@@@@@&$$$$&&$$$$$$|'```!&%;|&&&&&@@@@@@@@@@@@@@@&&&&%
###&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%:|&&&&&$$||$&$|%%%$$&&&@@@@@@@@$;`........``'::'`...```'``````:|$$$&@@&$&@@@@@@&@#@@####@#&&#@$|%&$$%%&&$$$$%!'`.`:!$@@&&&&@@@@@@@@@@@@@@&&&&&&&&%
###@&&&&&&&&&&&&&&&&&&&&&&&&&&|:!&&&&&&$$%||$&&$%%%$$&&&&@@@@@@@@@@&%:`.................`'````:!;;|$$$&&@@&&&&@@@@&&@########@!':|&$$%%$|;:;;!|%%%%||$@@&&&&&&&@&&&&&&&&&&&&&&&&&&&%
###@&&&&&&&&&&&&&&&&&&&&&&$!:|&&&&&&&&$$%|%$&&&$%%%$&&&&&@@@@@@@@@@@@&&$;`..............``'';|!;;;;|%$$$$&@@@&&&@@&&$$&&@@@@##@&%||%%%$!:|%%%%%||%!|$@@@&&&&&&&&$$$$$$&&&&&&&&&&&&&%
###@&&&&&&&&&&&&&&&&&&&|:!$&&&&&&&&&&$%%%%$$&&&$%%$$$$&&@#@@@@@@@@@@@&&&&&&|'...........``:!!;;;;;!!;|$&$%|&@@@&&&&&$!|$$$&@@#@@&%%%%$|'':!%%%%|!|$&&@@&&&&&&&$%%%%$$$$$&&$$$$$$&&&%
###@&&&&&&&&&&&&&&&|:;%&&&&&&&&&&&&$$%%%%$$&&&&$$$$$$$$&@#@@@@@@@@@&&&&&&&&&&&&|'.....`;%%!!!!;;;!!!!;!%$$&$|%@@@@@&&@$;:::!|%$&$%%%$%:'``';!!|||%$&@@@&&&&&&$%%%%%%%$$$$$%%%%$$$$$|
###@&&&&&&&&&$|:;%&&&&&&&&&&&&&&&$$%%$%%$&&&&&&$$$$%$$$&@@@@@@@@@##@&&&&&&&&&&&&&&%|%&&&&&$|;;;;;;;;;;;;!$&$&$|!%&@@@@@@&%;::!$$$$$$%;:```````;||||%$&&$$$$$$%|%%%%%%%$$$%%%%%%%%$%|
###@&&$%|||$&&&&&&&&&&&&&&&&&&$$$$%%$$%$&&&&&&&$$$%%$$&&@@@@@@@@@@@##@&&&&&&&&&&&&&&&&&&&&@%;;;;;;;::;;;;!!$&&$$%!;|$$$&&&$&&&$$$$$%!|$&%:...`.`;|!|||!;!|||||||%%%%%%$%%%||||%%%%%|
&&@@&&&&&&&&&&&&&&&&&&&&&&&$$$$$$%%$$%$&&&&&&&&$%%%%$$&&@@@@@@@@@@@@#@&@@&&&&&&&&&&&&&@###&%;;;;;;::::;;;!!!!|$$$&&%!:;!$&&&@&$$$&@&&&$%$&|``..'%#@@&$%%||||!;:'`';|%%$%%|||||||||||
###@&&&&&&&&&&&&&&&&&&&&$$$$$$$$%%$&&$$&&&&&&&&$%%%%$$&&&@@@@@@@@@@@@@@&&&&@@@@@&&@####$;':!!;;;::::;;;;!;!;::::;%&&&&&$$$&@&$$$@@$$$$$&@@@@$%@#@@##@@&%%||||||||%%%|!'`:!||||||||||
###@&&&&&&&&&&&&&&&&&$$$$$$$$$$$$$$$%%$$$$&&&&@$%%%%$$&&&&&@@@@@@@@@&&&&@@&&&&&&&@@@@|:':;;!!;;:::::::;;!!;:::::::::':::';$$$$$&&$&&&@@@&&@@@@@#######@@##@&%||||||||%%%%|!''!|||||!
###@&&&&&&&&&&&&&&$$$$$$$$$$$&&$$$$$%%$$$$$&&&&&$%%$$$&&&&&$&&&@@@@&&&&&&&&&&&&@@@%:''':;;;;;:::::::::;;;:::::::::::::;;!%$$$$$|:::|$&&$&@@@@@&$&@#####@@@@####@&$%||%%%||||||;:!||!
###@&&&&&&&&&&&$$$$$$$$$$$&&&&&$$&&$%%$$$&&&&&&&&$%$$$$$&&&&&&&@@@#@&&&&&&&&@##$;''''':;;;;;:::::::::;!;:::::::::::::::;%&$$$$|''':;%&%!;:'''':|%$&@@@@#@@&&&@##@&&@@$|%%|||||||!:;|
:;$@@&&&&&&&$$$$$$$$$$$&&&&&&&&&$$&&$$&&&&&&&&&&&$%%$$$&&&&&&&&&&&&@@#######@|:'''''';!!!;::::::;;!!!!;::::::::::::::::|$$$$$!'::;!!%&|;;''''''''''';$&@@#@&&$$&@&&@#@@@#####@$%||;:
''''':|$&$$$$$$$$$$&&&&&&&&&&&&&&$$&$$&&&&&&&&&&&&&$$$$$&&$$&&&&&@@@@@&$%$%|:''''''':;:::::::::::::;;:::::::::::::::::|$$$$$!::;;;;|&%;;:''''''''''''':!$&@@@&$$$$&################$
'''''''''';%$$&&&&&&&&&&&&&&&&&&&&$$$$&&&&&&&&&&&&&&$$$$$&@@@@@###@&&$%;''''''''':::;;:::::::::::;;:::'':::::::::::':|$$$$$!::;:::|&%;;:''''''''''''''```:%&@@&&&$$$&##############$
'''''''''''':':|&&&&&&&&&&&&&&&&&&&&$%$&&&&&&&&&&&&&&$$$$$&@@&@@@&$$%%!:''''''::::::!;::::::::::;;::::::::::::::''':|$$$$$|;;:::;%&|::'''''''''''''`.....``;$@@&&&&$$$&@###########$
;:'''''''''''''':::!$&&&&&&&&&&&&&&&&&%|$&&&&&&&&&&&&&&$$$$&$$$$$$|:!|;':::::::::::;!;::::::::;;:::::::::::::''''':|$$$$$|;::::|&&|::'''''''''''``........`''!&@@&&&&$$$&@#########$
.';;;;;:'''''''''''':::;%&@&&&&&&&&&&&&%$&&$$$$&&&&&&$&@&&&$$$$%!:::!|;::::::::::::!!;::::::!;::::::::::::::''''':|&$$$$|;::::|&%;;:'``''''''''````......````'!$@@&&&&&$$$&@#######$
;;;:`.`:;;;;::'''''''''''':;%@@@&&&&&&&&$$$&&&&&&&&&&@@&!::':'':::::||;::::::::::::!!;:::;!!;;:::::::::::::::''':%&$$$$|;:::;%&|:::'`````````'''```..`...````''!$@@&&&&&&&$$&@#####$
;;;;;;;;;'..';;;;::''''''''''':|@@@@&&&&&&$%$&&&&&&&@@%:::::::::::::!|;:::::''''''';!;:;!!;:::::::::::::::::''':%&$$$%|;:::|&%;;:'''```````'''''``...      ```''!&@&&&&&&&&&&&&@###$
:::;;;;;;;;!;;;'':;;;;:'''''''''':!&@@@&&&&&$$&&&&@@@$;::::::::::::';|:``````````'';!;;;:'''```````````````''''|$$$$%|;::|&$!;;:'````````''::''``....      .``'':%@&&&&&&&&&&&&&&@#$
::::::::;;;;;;;;;;;;:'':;;:''''''''':;%@@@@&&&&$&@@@$;''''''':''`''`:|;````````````:!!:'''``.........``......`!$%%%%|;;|&$!:;'`````````'''::''.     ..    `''``''!$&&@@&&&&&&&&&&&&%
###@%!:::::::;;;;;;;;;;;;;;;;::'''''::::|&@@@&&&&&&%'```.....````''`'||'``````````';;'''``................. .!$%%%%|!%&$!:;:'``'''````'::::''.       ....``''``'''|@&&&@&&&@&&&&&&$|
####@&&&@&|;::::::;;;;;;;;;;;;;;;:'''''''::!&@@@@@%:````......```'```;%;`````````''''``.................   .!$%%%%%$&%;:::''```'''```'::::'`.         ...``'```''';$@&&&@@&&&&&&&&&%
####@&&&&&&&&&$!:::::::;;;;;;;;;;;;;:''''''':|@@@$;````.......``''```'!%;``````''''``.......      ....    .;%%%%%%$%;::'''`````''''`'::::`.             ...`````'''|@&&&&@@&&&&&&&&%
####@&&&&&&&&&&&&&&|;::::::;;;;;;;;;;;;:::'':;;%&;````.........``'````:||:```':''`......                .`:|%%%%%|;::''''``````'''''::::`.               ....```'''!$@&&&&@@&&&&&&&%
####@&&&&&&&&&&&&&&&&&&|::::::::;;;;;;;;;:::::;;'````..........``'`````:||:':''`......                .`'!$%%%%|;:''```````````'''''::;'.                 ......``':%@@&&&&&@&&&&&&%
####@&&&&&&&&&&&&&&&&&&&&&$!:::::::;;;;;;;;;;;;'`````..........`''``````:||:''`.  .                .``!$&$%%%%%;'''`````````````'':::;;`                   .....```'!&@&&&&&&@&&&&&%
####@&&&&&&&&&&&&&&&&&&&&&&&&&|;:::::;;;;;;;;;:``````...........''````':':|%!'.                .``'|$&|;|%|%%%!''````...`````````':::;;`                    .....```'|@&&&&&&&@&&&&%
####@&&&&&&&&&&&&&&&&&&&&&&&&&&&$!::::::;;;;;:``````....``......''``':'''':!|%;..         ..``:|%$|;::;|%||%%!'`````......```''`'':::;:'   .......           ....````:%@&&&&&&@@&&&%
####@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%;:::::;;:```````....`.   ...`'':''`.  .':!||;````````';|%%|;::::';|%||%%;'```.........```'''''::::;'. ....````........  ......````:%@&&&&&&@@&&%
####@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&|:::::'```````...``.   ..'::'``.   .```':;!||!;;!||!;::::''``';|%||%|;'```..........```'''''::::;:.....``````````...........`````;&&&&&&&@@@&%
*/

long long dp[155][4][155][155],sum[4][155][155];
int n,m;

int main(){
	scanf("%d%d",&n,&m);
	long long ans=0;
	for(int k=1;k<=m;k++){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				dp[k][0][i][j]++;
			}
		}
		memset((long long*)sum,0,sizeof(sum));
		for(int f=0;f<4;f++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					sum[f][i][j]=sum[f][i-1][j]+sum[f][i][j-1]-sum[f][i-1][j-1]+dp[k-1][f][i][j];
					sum[f][i][j]%=Mod;
					if(sum[f][i][j]<0){
						sum[f][i][j]+=Mod;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				dp[k][0][i][j]+=sum[0][j][j]+sum[0][i-1][i-1]-sum[0][i-1][j]-sum[0][j][i-1];
				dp[k][0][i][j]%=Mod;
				if(dp[k][0][i][j]<0){
					dp[k][0][i][j]+=Mod;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				dp[k][1][i][j]+=sum[1][i][j]+sum[1][0][i-1]-sum[1][0][j]-sum[1][i][i-1];
				dp[k][1][i][j]+=sum[0][i-1][j]+sum[0][0][i-1]-sum[0][0][j]-sum[0][i-1][i-1];
				dp[k][1][i][j]%=Mod;
				if(dp[k][1][i][j]<0){
					dp[k][1][i][j]+=Mod;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				dp[k][2][i][j]+=sum[2][j][n]+sum[2][i-1][j-1]-sum[2][i-1][n]-sum[2][j][j-1];
				dp[k][2][i][j]+=sum[0][j][n]+sum[0][i-1][j]-sum[0][i-1][n]-sum[0][j][j];
				dp[k][2][i][j]%=Mod;
				if(dp[k][2][i][j]<0){
					dp[k][2][i][j]+=Mod;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				dp[k][3][i][j]+=sum[3][i][n]+sum[3][0][j-1]-sum[3][0][n]-sum[3][i][j-1];
				dp[k][3][i][j]+=sum[2][i-1][n]+sum[2][0][j-1]-sum[2][0][n]-sum[2][i-1][j-1];
				dp[k][3][i][j]+=sum[1][i][n]+sum[1][0][j]-sum[1][0][n]-sum[1][i][j];
				dp[k][3][i][j]+=sum[0][i-1][n]+sum[0][0][j]-sum[0][0][n]-sum[0][i-1][j];
				dp[k][3][i][j]%=Mod;
				if(dp[k][3][i][j]<0){
					dp[k][3][i][j]+=Mod;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int f=0;f<4;f++){
					ans+=dp[k][f][i][j];
				}
			}
		}
	}
	ans%=Mod;
	printf("%d\n",ans);
	return 0;
}