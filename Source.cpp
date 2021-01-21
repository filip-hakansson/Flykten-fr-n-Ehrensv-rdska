#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <cstdio>
using namespace std;


// |VIKTIGT| programmet går ut på att funktionerna anropar varandra och på så vis skapar en oändlig loop där användaren kan gå fram och tillbaka mellan alla "rummen" i spelet. 
//genom att hitta föremål och prata med rätt personer togglar spelaren variabler som låser upp ny aktioner i spelet. När spelaren avklarat en rad uppgifter togglas sista variabeln
//som låser upp spelets slut och när den funktionen anropas vinner spelaren och programmet avslutas.

//funktioner för start och slut av spelet
void start();
void slut();



// följande är funktioner för alla rummen man kan vara i, när funktionen anropas presenteras miljöbeskrivningen av detta det anropade rummet.
// anledningen till att dela upp miljöbeskrivningen och valen är att gör man upprepade val i ett rum T.ex plocka upp bok sedan prata med "person" så behövs inte miljöbeskrivningen upprepas
void korridorenMiljö();
void grupprummetMiljö();
void trappornaMiljö();
void entrenMiljö();
void expeditionenMiljö();
void toaletternaMiljö();

// följande är funktionerna för de val man kan göra i varje rum 
void korridorenVal();
void grupprummetVal();
void trappornaVal();
void entrenVal();
void expeditionenVal();
void toaletternaVal();




// följande är funktionerna för alla karaktärerna och utav amma anledning som valen i rum är även dessa funktioner uppdelade i en funktion för konversation/introduktion
//och en för val man eventuellt gör efter
// presenterar konversation
void anton();
void bastian();
void emil();
void hugo();
void liam();
void dennis();
void herman();
void alfred();

// valet som görs efter konversation/introduktion
void antonVal();
void bastianVal();
void emilVal();
void hugoVal();
void liamVal();
void dennisVal();
void hermanVal();
void alfredVal();
void alfredsGåtorVal();

void emilsLek();
void alfredsGåtor();

// variabler för föremål i spelet
// 0 innebär att spelaren inte har plockat upp föremålet, 1 innebär att spelaren bär på föremålet, 3 innebär att föremålet har konsumerats. 
int monster = 1;
int blyertspenna = 0;
int sjukanmälan = 0;
int tejp = 0;
int trasigSladd = 0;
int helSladd = 0;
int usb = 0;
int nyckel = 0;
int adapter = 0;
int pennVässare = 0;

// generell variabel för när spelaren gör ett val
int val;
int omstart=1;
string sval;


// funktioner för att plocka upp föremål
void fsjukanmälan();
void ftejp();
void ftrasigSladd();

// gåtorna som används av alfred när man pratar med honom, varje fält har en tilldelad gåta.
const string alfredsGåtorText[14] = {"Vad blir blötare och blötare ju mer du torkar?","Vilken råtta äter inte ost?","Vad går upp och ner utan att röra sig?", 
"Vad kan gå men inte springa?", "Vem går upp varje morgon utan att ha sovit en blund?","Vad går över vatten utan att röra sig?","Vad går genom städer utan att röra sig?", 
"Vad är det som kan sitta i ett hörn men ändå åka jorden runt?", "Vad blir större och större ju mer man tar bort, men mindre ju mer man lägger till?",
"På vilken sida av fåret är det mest ull?", "Vad är det som har fyra ben på dagen och sex ben på natten?", "Vad gör alla i hela världen i samma takt?", 
"Vilken sten är ihålig?", "Vem har hals men inget huvud?"};




int main()
{
	setlocale(LC_ALL, "swedish");

	if (omstart == 1)
	{
		start();// main används bara för att ställa in språket och kickstarta funktionsloopandet
	}
	else
	{
		return 0;
	}
}



void start()
{
	cout << "Du tar en titt på klockan. visarna står på kvart över två, endast fem minuter har gått sedan du senast tog dig en titt ";
	cout << "och det återstår fortfarnande 2 timmar av mattelektionen.Tiden tycks gå baklänges. Du bestämmer dig för att du har fått nog ";
	cout << "och ber matteläraren om att få gå på toa, utan svar drar du på dig väskan och smiter smitdit ut ur klassrummet. Väl ute i ";
	cout << "korridoren tar du ett uppfriskande andetag och känner vittringen av frihet men du är inte fri än, flykten från Ehrensvärdska har bara börjat...";
	cout << "\n\n";

	korridorenMiljö();
	korridorenVal();
}
void slut()
{
	string svar;
	cout << "Stort tack för att du spelade mitt spel, vill du spela igen?\n:";
	getline(cin, svar);
	getline(cin, svar);

	if (svar == "ja" || svar == "Ja")
	{
		
		//alla variabler återställs
		int monster = 0;
		int bläckpenna = 0;
		int sjukanmälan = 0;
		int tejp = 0;
		int trasigSladd = 0;
		int helSladd = 0;
		int usb = 0;
		int nyckel = 0;
		
		start();
	}
	else if (svar == "nej" || svar == "Nej")
	{
		return;
	}
	else
	{
		cout << "Svara med ja eller nej";


		slut();
	}
}

void korridorenMiljö()
{
	cout << "I den långsmala korridoren sitter endast två personer en bit ifrån varandra, närmst dig sitter bastian och pluggar och lite längre ner i korridoren sitter anton från. ";
	cout << "Längs med korridoren står flertalet bord och stolar och en rad dörrar till grupprum utgör den ena väggen, den andra väggen består utav stora panoramafönster som vättar ut mod gatan.";
	cout << " Du granskar väggen med grupprummen och lägger märke till att det sitter ett handtag till brandlarmet där, under handtaget sitter det en skylt som säger \"Vid aktivering färgas användaren\".";
	cout << " Genom glasetrutorna i dörrarna till grupprumen ser du att endast ett lyser och drar slutsatsen att det är de enda upptagna rummet.";
	cout << " I din ände av korridoren börjar trapphuset som leder upp till första plan och i den motsatta änden ligger endast fler upptagna klassrum.";
}
void grupprummetMiljö()
{
	cout << "I grupprummet sitter Emil och Hugo. När du kliver in tittar emil upp på dig med ett lurigt leende men hugo verkar vara som förhexad i matteboken. Överlag är grupprummet ";
	cout << "ganska kalt och innehåller inget märkvärdigt.";
}
void trappornaMiljö()
{
	cout << "Du står i trapphuset och ser liam sittandes vid en vägg. Trappan känns lite hal och du lägger märke till att den är nystadad, ";
	cout << "inte ens ett godispapper ligger framme. Det runda trapphuset utan fönster påminner om äldre arkitektur och är tre våningar högt, ";
	cout << "Övre delen av trapphuset leder till korridoren, mittplanet leder till två rum, Expeditionen och toaletterna och nedre delen av trappan leder till entren \n\n";
}
void entrenMiljö()
{
	if (sjukanmälan == 0)// om man inte tidigare har plockat upp sjukanmälan så säger texten att det ligger på golvet
	{
	cout << "Du ser dig om i entren, en grupp chappare står vid ytterdörren och du ryser vid blotta tankan av att gå förbi dom. Dennis sitter i en av entrens många sofforna och pillar med en rasberry PI. "; 
	cout << "Utöver Dennis och eleverna från chapman är entren helt tom och när du tar dig en närmare titt på golvet och ser du ett ihopskrynklat papper längs med en av väggarna.\n\n";
	}
	else// om man har plockat upp sjukanmälan så säger texten inget om sjukanmälan
	{
	cout << "Du ser dig om i entren, en grupp chappare står vid ytterdörren och du ryser vid blotta tankan av att gå förbi dom. Dennis sitter i en av entrens många sofforna och pillar med en rasberry PI. ";
	cout << "Utöver Dennis och eleverna från chapman är entren helt tom, bara ensamma soffor och bord finns där.\n\n";
	}
}
void expeditionenMiljö()
{
	if (tejp == 0)// om man inte tidigare har plockat upp sladden säger texten att sladden ligger på bordet
	{
	cout << "Expeditionen utgörs av en korrt korridor med ett fåtal dörrar, innanför dess dörrar sitter rektorerna och skolans administrativa personal. I korridoren finns också ett bord med två fotöljer ";
	cout << "samt ett öppet skåp med tomma hyllplan. I en av fotöljerna sitter herman och på bordet mellan fotöljerna ligger en trasig sladd";
	}
	else// om man har plockat upp sladden så säger texten inget om sladden
	{
		cout << "Expeditionen utgörs av en korrt korridor med ett fåral dörrar, innanför dess dörrar sitter rektorerna och skolans administrativa personal. I korridoren finns också ett bord med två fotöljer ";
		cout << "samt ett öppet skåp med tomma hyllplan. I en av fotöljerna sitter herman.";
	}
}	
void toaletternaMiljö()
{
	if (trasigSladd == 0)// om man inte tidigare har plockat upp tejpen säger texten att tejpen ligger vid soptunnan
	{
	cout << "De två toaletterna är upptagna och utanför står Alfred på tur och spelar på sin mobil. Alfred lutar sig emot en soptunna som står utanför den ena toaletten och vid den på golvet ligger en rulle eltjep. ";
	cout << "Mitt emot toaletterna finns det en dörr som leder till en evakueringstrappa. Toaletterna och evakueringstrappan befinner sig i ett midre samlingsrum som leder vidare till två andra klassrum. ";
	cout << "I rummet finns ochså ett runt bord med flertalet stolar samt en bokhylla som går från golv till tak.";
	}
	else// om man har plockat upp tejpen så säger texten inget om tejpen
	{
		cout << "De två toaletterna är upptagna och utanför står Alfred på tur och spelar på sin mobil. Alfred lutar sig emot en soptunna som står utanför den ena toaletten. ";
		cout << "Mitt emot toaletterna finns det en dörr som leder till en evakueringstrappa. Toaletterna och evakueringstrappan befinner sig i ett midre samlingsrum som leder vidare till två andra klassrum. ";
		cout << "I rummet finns ochså ett runt bord med flertalet stolar samt en bokhylla som går från golv till tak.";
	}
	
}

void korridorenVal()
{
	cout << "\n1: Prata med Bastian\t 2: Prata med Anton\t 3: Gå till grupprummet\t 4: Gå till trapphuset\n\n";
	cin >> val;

	switch(val)
	{
		case 1:
		{
			bastian();
			bastianVal();
		}
		case 2:
		{
			anton();
			antonVal();
		}
		case 3:
		{
			grupprummetMiljö();
			grupprummetVal();
		}
		case 4:
		{
			trappornaMiljö();
			trappornaVal();
		}
		default:
		{
			cout << "du valde inte ett giltigt alternativ";
			korridorenVal();
		}
	}
}
void grupprummetVal()
{
	cout << "\n1: Prata med Emil\t 2: Prata med Hugo\t 3: Gå till korridoren\n\n";
	cin >> val;

	switch (val)
	{
		case 1:
		{
			emil();
			emilVal();
		}
		case 2:
		{
			hugo();
			hugoVal;
		}
		case 3:
		{
			korridorenMiljö();
			korridorenVal();
		}
		default:
		{
			grupprummetVal;
		}
	}
}
void trappornaVal()
{
	cout << "\n1: Prata med liam\t 2: Gå till Entrén\t 3: Gå till Expeditionen\t 4: Gå till toaletterna\t 5: Gå till korridoren\n\n";
	cin >> val;
	switch (val)
	{
		case 1:
		{
			liam();
			liamVal();
		}
		case 2:
		{
			entrenMiljö();
			entrenVal();
		}
		case 3:
		{
			expeditionenMiljö();
			expeditionenVal();
		}
		case 4:
		{
			toaletternaMiljö();
			toaletternaVal();
		}
		case 5:
		{
			korridorenMiljö();
			korridorenVal();
		}
	}
}
void entrenVal()
{
	if (sjukanmälan == 0)// om man inte tidigare har plockat upp sjukanmälan ges alternativet till att plocka upp det
	{
		cout << "\n1: Prata med Dennis\t 2: Gå till trapphuset\t 3: Plocka upp pappret";
		cin >> val;

		switch (val)
		{
			case 1:
			{
				dennis();
			}
			case 2:
			{
				trappornaMiljö();
				trappornaVal();
			}
			case 3:
			{
				fsjukanmälan();
			}
			default:
			{
				entrenVal();
			}
		}
	}
	else// har man redan plockat upp sjukanmälan försvinner det alternativet 
	{
		cout << "\n1: Prata med Dennis\t 2: Gå till trapporna";
		cin >> val;

		switch (val)
		{
			case 1:
			{
				dennis();
				dennisVal();
			}
			case 2:
			{
				trappornaMiljö();
				trappornaVal();
			}
			default:
			{
				entrenVal();
			}
		}
	}
}
void expeditionenVal()
{
	if (tejp == 0)// om man inte tidigare har plockat upp sladden ges alternativet till att plocka upp sladden
	{
		cout << "\n1: Prata med Herman\t 2: Gå till trapphuset\t 3: Plocka upp sladden";
		cin >> val;

		switch (val)
		{
			case 1:
			{
				herman();
				hermanVal();
			}
			case 2:
			{
				trappornaMiljö();
				trappornaVal();
			}
			case 3:
			{
				ftrasigSladd();
			}
			default:
			{
				expeditionenVal();
			}
		}
	}
	else// har man redan plockat upp tejpen försvinner det alternativet 
	{
		cout << "\n1: Prata med Herman\t 2: Gå till trapporna";
		cin >> val;

		switch (val)
			{
			case 1:
			{
				herman();
				hermanVal();
			}
			case 2:
			{
				trappornaMiljö();
				trappornaVal();
			}
			default:
			{
				expeditionenVal();
			}
		}
	}
}
void toaletternaVal()
{
	if (trasigSladd == 0)// om man inte tidigare har plockat upp tejpen ges alternativet till att plocka upp den
		{
			cout << "\n1: Prata med Alfred\t 2: Gå till trapphuset\t 3: Plocka upp tejpen";
			cin >> val;

			switch (val)
			{
			case 1:
				{
					alfred();
				}
				case 2:
				{
					trappornaMiljö();
					trappornaVal();
				}
				case 3:
				{
					ftejp();
				}
				default:
				{
					toaletternaVal();
				}
			}
		}
	else// har man redan plockat upp tejpen försvinner det alternativet 
	{
		cout << "\n1: Prata med Herman\t 2: Gå till trapporna";
		cin >> val;

		switch (val)
		{
			case 1:
			{
				alfred();
			}
			case 2:
			{
				trappornaMiljö();
					trappornaVal();
			}
			default:
			{
				toaletternaVal();
			}
		}
	}	
}

void anton()
{
	if (helSladd == 1)//text som presenteras om anton redan har lagat sladden åt en.
	{
		cout << "-glömde borrt att vi hade matteprov imon så jag måste plugga, hinner inte hjälpa dig mer tyvärr. Vi ses!\n";

		korridorenVal();
	}
	else if (trasigSladd == 1 && tejp == 1 && helSladd == 0)
	{
		cout << "-Hej, ser att du har en trasig sladd i handen, har du lite el-tejp kan jag nog laga den. Du har det? Det här fixar jag.\n\n anton gav tillbaka en fungerande sladd\n";

		trasigSladd = 3;
		helSladd = 1;

		korridorenVal();
	}
	else if (trasigSladd == 1 && tejp == 0 && helSladd == 0)//text som presenteras om man har plockat upp sladden men inte tejpen.
	{
		cout << "-Tja, ser att du har en trasig sladd i handen, i det skicket lär den ju inte fungera. Om du hittar något att laga den med kan jag hjälpa dig.\n";

		korridorenVal();
	}
	else if (trasigSladd == 0 && tejp == 1 && helSladd == 0)//text som presenteras om man har plockat upp tejpen men inte sladden.
	{
		cout << "-Tja, ser att du har en rulle el-tejp i handen, vad ska du med den till? laga något eller? Behöver du hjälp så är det bara att komma tilbaka.\n";
		
		korridorenVal();
	}
	else //texten som presenteras om man inte har något av de föremål som behövs.
	{
		cout << "-Hej! Orkar inte du heller med matten? Näh tänkte väl det, har inte heller någon lust att jobba. Om du har tråkigt eller behöver hjälp med något får du gärna komma tillbaka, vi hörs!\n";

		korridorenVal();
	}
}
void bastian()
{
	if (monster == 0)
	{
		cout << "-Hej, vad gör du? Ser ut som att du bara strosar runt i korridoren. Hade gärna följt med dig men jag måste bli färdig med fysik pluggandet, har så svårt att koncentrera mig bara. ";
		cout << " Om du hittar något som kan pigga upp mig får du gärna komma tillbaka.";

		korridorenVal();
	}
	else
	{
		cout << "Hej igen, vad sa du? Hade du en monster till mig? Eyyy tack som fan, vaf skull jag göra för att få den sa du? Dra i brandlarmet? Lätt värt det jag tror inte den spaken fungerar ändå.\n";
		cout << "Bastian drog i brandlarmet som mot hans gissningar faktiskt fungerade. Det rang högt i hela huset och elever strömmade ut från alla klassrum. Bastian tittade ner på sin lila färgade hand ";
		cout << "medan du snabbt vände på klacken och styrde dina steg mot entren. Till din lättnade hade chapman eleverna chingrats och ingenting stod ivägen för din frihet. Ouppmärkt gled du ut ur entréns ";
		cout << "stora dörrar och inom kort satt du på bussen på väg hem med ett brett leende på läpparna.";

		slut();

	}
}
void emil()
{
	if (blyertspenna == 0)
	{
		cout << "-hallå jag har tråkigt vill du köra en liten lek?" << endl;
		emilVal();
	}
	else
	{
		cout << "Jag måste också få något gjort på denna lektionen så du får hitta någon annan att leka med.";
		
		grupprummetVal();
	}
	
}
void hugo()
{
	if (usb == 0)
	{
		cout <<	"Du knackar Hugo på axeln." << endl;
		cout << "-Oj hej jag såg dig inte jag var lite fokuserad på en matteuppgift, jag kan inte lyckas lösa den. Vill du hjälpa mig?\n" << endl;
		
		hugoVal();
	}
	else
	{
		cout << "Tack för att du hjälpte mig, jag måste räkna vidare nu";
		grupprummetVal();
	}
}
void liam()
{
	if (nyckel == 1)//text som presenteras om liam redan har gett en nyckeln.
	{
		cout << "-Tack för hjälpen, pappa kommer när som helst så jag hinner inte hjälpa dig mer.\n";

		trappornaVal();
	}
	else if (adapter == 1 && helSladd == 1 && nyckel == 0)//text som presenteras om man har lagat sladden och har fått väggadaptern.
	{
		cout << "-Hej! Har du en laddare jag kan låna? Jag glömde min hemma och min mobil har fått slut på batteri. Jag lovade pappa att jag skulle ringa när jag hade slutat men nu kan jag inte det så jag är fast här tills ";
		cout << "vidare. Oh, du har en laddare? härligt! kan jag få låna den?.\n";
		liamVal();
	}
	else if (helSladd == 1 && adapter == 0)//text som presenteras om man har lagat sladden men har inte väggadaptern.
	{
		cout << "-Hej! Har du en laddare jag kan låna? Jag glömde min hemma och min mobil har fått slut på batteri. Jag lovade pappa att jag skulle ringa när jag hade slutat men nu kan jag inte det så jag är fast här tills vidare. ";
		cout << "Okej så du har en fungerande sladd men ingen väggadapter? Kan tyvärr inte bara sätta i sladden i väggen men kom gärna tillbaka om du hittar en adapter.\n";
		trappornaVal();
	}
	else if (trasigSladd == 0 && adapter == 1)//text som presenteras om man har plockat fått adaptern men inte plockat upp sladden.
	{
		cout << "-Hej! Har du en laddare jag kan låna? Jag glömde min hemma och min mobil har fått slut på batteri. Jag lovade pappa att jag skulle ringa när jag hade slutat men nu kan jag inte det så jag är fast här tills vidare. ";
		cout << "Bra att du har hittat en adapter men utan en sladd också blir det nog svårt att ladda mobilen, kom tillbaka om du hittar en fungerande sladd.\n";
		trappornaVal();
	}
	else if (trasigSladd == 1 && adapter == 1)//text som presenteras om man har plockat fått adaptern men inte lagat sladden.
	{
		cout << "-Hej! Har du en laddare jag kan låna? Jag glömde min hemma och min mobil har fått slut på batteri. Jag lovade pappa att jag skulle ringa när jag hade slutat men nu kan jag inte det så jag är fast här tills vidare. ";
		cout << "Bra att du har hittat en adapter och en sladd men med skicket på den sladden lär den nog inte ladda någonting, kom tillbaka om du lyckas laga den.\n";
		trappornaVal();
	}
	else if (trasigSladd == 1 && adapter == 0)//text som presenteras om man inte har plockat fått adaptern och inte lagat sladden.
	{
		cout << "-Hej! Har du en laddare jag kan låna? Jag glömde min hemma och min mobil har fått slut på batteri. Jag lovade pappa att jag skulle ringa när jag hade slutat men nu kan jag inte det så jag är fast här tills vidare. ";
		cout << "Bra att du har hittat en sladd tyvärr ser det inte ut som att den fungerar. Kan tyvärr inte bara sätta i sladden i väggen men kom gärna tillbaka om du hittar en adapter eller lagar sladden.\n";
		trappornaVal();
	}
	else//texten som presenteras om man inte har något av de föremål som behövs.
	{
		cout << "-Hej! Har du en laddare jag kan låna? Jag glömde min hemma och min mobil har fått slut på batteri. Jag lovade pappa att jag skulle ringa när jag hade slutat men nu kan jag inte det så jag är fast här tills vidare. \n";
		cout << "Om du hittar något jag kan använda för att ladda min mobil så får du gärna komma tillbaka.";
		trappornaVal();
	}
}
void dennis()
{
	if (monster == 1)//text som presenteras om dennis redan har gett en monstern.
	{
		cout << "-Tack för hjälpen men nu måste jag fokusera lite.\n";

		entrenVal();
	}
	else if (usb == 1 && helSladd == 1 && monster == 0)//text som presenteras om man har lagat sladden och har hittat usbstickan.
	{
		cout << "-Hej, elkabeln till min rasberry PI är trasig och jag behöver ett usb för att uppgradera mjukvaran, du har båda? Du skojar vad är chansen för det? ";
		cout << "Du kan få en burk monster om jag kan får låna sladden och usbstickabn till imorgon.\n";
		dennisVal();
	}
	else if (helSladd == 1 && usb == 0)//text som presenteras om man har lagat sladden men har inte usbstickan.
	{
		cout << "-Hej, elkabeln till min rasberry PI är trasig och jag behöver ett usb för att uppgradera mjukvaran, jasså du har en fungerande sladd? Behöver tyverr också en usbsticka för att få PIen att funka. ";
		cout << "Kom gärna tillbaka om du hittar en usbsticka.\n";
		entrenVal();
	}
	else if (trasigSladd == 0 && usb == 1 )//text som presenteras om man har plockat upp usbstickan men inte plockat upp sladden.
	{
		cout << "-Hej, elkabeln till min rasberry PI är trasig och jag behöver ett usb för att uppgradera mjukvaran, jasså du har ett usb men ingen sladd? Blir tyverr lite svårt att överföra ";
		cout << "mjukvara till en dator utan ström. Kom gärna tillbaka om du hitter en sladd.\n";
		entrenVal();
	}
	else if (trasigSladd == 1 && usb == 1)//text som presenteras om man har plockat upp usbstickan men inte lagat sladden.
	{
		cout << "-Hej, elkabeln till min rasberry PI är trasig och jag behöver ett usb för att uppgradera mjukvaran, jasså du har ett usb men ingen fungerande sladd? Blir tyverr lite svårt att överföra ";
		cout << "mjukvara till en dator utan ström. Kom gärna tillbaka om du hitter en fungerande sladd.\n";
		entrenVal();
	}
	else if (trasigSladd == 1 && usb == 0)//text som presenteras om man inte har plockat upp usbstickan och inte lagat sladden.
	{
		cout << "-Hej, elkabeln till min rasberry PI är trasig och jag behöver ett usb för att uppgradera mjukvaran, jasså du har sladd men den fungerar inte? Blir tyverr lite svårt att överföra ";
		cout << "mjukvara till en dator utan ström och utan en usbsticka. Kom gärna tillbaka om du har lagat sladden eller hittat en usbsticka.\n";
		entrenVal();
	}
	else//texten som presenteras om man inte har något av de föremål som behövs.
	{
		cout << "-Hej, elkabeln till min rasberry PI är trasig och jag behöver ett usb för att uppgradera mjukvaran, Kom gärna tillbaka om du hitter en fungerande sladd eller en usbsticka.\n";
		entrenVal();
	}
}
void herman()
{
	if (adapter == 1)
	{
		cout << "-Tack för att du fixade papper och penna till mig, administratören ska bara godkänna min sjukanmälan och sedan kan jag gå hem.";
		expeditionenVal();
	}
	else if (blyertspenna==1 && sjukanmälan==1 && pennVässare==1)
	{
		cout << "wow du har ju all jag behöver! om jag får pennan, pennvässaren och sjukanmälan så kan du få den här väggutatag till sladd adaptern./n";
		hermanVal();
	}
}
void alfred()
{
	if (pennVässare == 0)
	{
	cout << "Står på kön till toan? Nej jag står bara här så det ser ut som att jag står i kön till toan, då ifrågasätter inga lärare att jag står här och spelar och jag slipper lektionen, bra va? ";
	cout << "Du nu när du ändå är har så kan jag få testa några gåtor på dig? jag ska använda dom i ett svenska projekt och jag behöver vet om dom är lagom svåra.";

	alfredVal();
	}
	else
	{
	cout << "Står på kön till toan? Nej jag står bara här så det ser ut som att jag står i kön till toan, då ifrågasätter inga lärare att jag står här och spelar och jag slipper lektionen, bra va? ";

	toaletternaVal();
	}
}

void antonVal()
{

}
void bastianVal()
{

}
void emilVal()
{
	string svar;
	cout << "Vill du testa Emils lek?\n:";
	getline(cin,svar);//första getlinen clearar cin buffern för andra getlinen
	getline(cin, svar);

	if (svar == "ja" || svar == "Ja")
	{
		emilsLek();
	}
	else if (svar == "nej" || svar == "Nej")
	{
		grupprummetVal();
	}
	else if (svar != "nej" || svar == "Nej" || svar == "ja" || svar == "Ja")
	{
		cout << "Svara med ja eller nej";

		emilVal();
	}
}
void hugoVal()
{
	string svar;
	cout << "Vill du hjälpa hugo?\n:";
	getline(cin, svar);

	if (svar == "ja" || svar == "Ja")
	{
		cout << "-Uppgiften är föränkla följande så långt som möjligt: x(x^8+2)+2x^9-2x \nSvar:";

		string mattesvar;
		getline(cin, mattesvar);

		if (mattesvar == "3x^9")
		{
			cout << "Wow det var rätt svar! att jag inte tänkte på det... här du kan få denna usbstickan som tack, jag behöver ändå inte den.\n\nHugo gav dig en usb sticka.\n\n";

			usb = 1;
			
			grupprummetVal();
		}
		else
		{
			cout << "-nja jag tror inte det var riktigt rätt\t\t(tips; glöm inte att du kan skriva potenser med ^ tecknet)";

			hugoVal();
		}
	}
	else if (svar == "nej" || svar == "Nej")
	{
		grupprummetVal();
	}
	else
	{
		cout << "Svara med ja eller nej";

		hugoVal();
	}
}
void liamVal()
{
	cout << "Vill du låna ut sladden och adaptern till Liam?\n:";
	getline(cin, sval);
	getline(cin, sval);
	if (sval == "ja" || sval == "Ja")
	{
		cout << "Du bytte med dennis och fick en burk monster.";
		adapter = 3;
		helSladd = 3;
		nyckel = 1;
		trappornaVal();
	}
	else if (sval == "nej" || sval == "Nej")
	{
		cout << "-Synd att du inte ville byta, jag får väl hitta något annat sätt att ta mig hem.\n";
		trappornaVal();
	}
	else
	{
		cout << "Svara med ja eller nej";
		liamVal();
	}
}
void dennisVal()
{
	cout << "Vill du byta med Dennis?\n:";
	getline(cin, sval);
	getline(cin, sval);
	if (sval == "ja" || sval == "Ja")
	{
		cout << "Du bytte med dennis och fick en burk monster.";
		usb = 3;
		helSladd = 3;
		monster = 1;
		entrenVal();
	}
	else if (sval == "nej" || sval == "Nej")
	{
		cout << "-Synd att du inte ville byta, om du ändrar dig får du gätna komma tilbaka.\n";
		entrenVal();
	}
	else
	{
		cout << "Svara med ja eller nej";
		dennisVal();
	}
}
void hermanVal()
{
	cout << "Vill du byta med Herman?\n:";
	getline(cin, sval);
	getline(cin, sval);
	if (sval == "ja" || sval == "Ja")
	{
		cout << "Du bytte med Herman och fick en väggadapter.";
		pennVässare = 3;
		blyertspenna = 3;
		sjukanmälan = 3;
		adapter = 1;
		expeditionenVal();
	}
	else if (sval == "nej" || sval == "Nej")
	{
		cout << "-Synd att du inte ville byta, om du ändrar dig får du gärna komma tilbaka om du ångrar dig.\n";
		expeditionenVal();
	}
	else
	{
		cout << "Svara med ja eller nej";
		hermanVal();
	}
}
void alfredVal()
{
	string svar;
	cout << "Vill du höra alfreds gåtor?\n:";
	getline(cin, svar);//första getlinen clearar cin buffern för andra getlinen
	getline(cin, svar);

	if (svar == "ja" || svar == "Ja")
	{
		alfredsGåtor();
	}
	else if (svar == "nej" || svar == "Nej")
	{
		toaletternaVal();
	}
	else if (svar != "nej" || svar == "Nej" || svar == "ja" || svar == "Ja")
	{
		cout << "Svara med ja eller nej";

		alfredVal();
	}
}
void alfredsGåtorVal()
{
	string svar;
	cout << "Det var inte rätt svar vill du ha en ny gåta?";
	getline(cin, svar);
	if (svar == "ja" || svar == "Ja")
	{
		cout << "kul, här kommer en ny gåta";
		alfredsGåtor();
	}
	else if (svar == "nej" || svar == "Nej")
	{
		cout << "det var ju synd, hoppas vi ses snart igen!";
		toaletternaVal();
	}
	else if (svar != "nej" || svar == "Nej" || svar == "ja" || svar == "Ja")
	{
		cout << "Svara med ja eller nej";

		alfredsGåtorVal();
	}
}

void fsjukanmälan()
{
	cout << "Du polockade upp pappret som visade sig vara en sjukanmälan";
	sjukanmälan = 1;
	entrenVal();
}
void ftejp()
{
	cout << "Du plockade upp tejpen. Den är användbar om man behöver laga någonting";
	
	tejp = 1;

	expeditionenVal();
}
void ftrasigSladd()
{
	cout << "Du plockade upp den trasiga sladden, i detta skicket är den oduglig.";

	trasigSladd = 1;

	toaletternaVal();
}

void emilsLek()
{
	
	int lekSvar;
		
	srand(time(0));//slumptalsgenerator
	int slumptal = (rand() % 10 + 1);

	cout << "-Jag tänker på ett tal mellan 1-10 och du får två försök på dig att gissa rätt okej? Varsågod och gissa:" << slumptal;
		cin >> lekSvar;

	if (lekSvar == slumptal)		
	{
			cout << "-Wow du gissade rätt på första försöket! Här får den blyertspenna som pris!\nEmil gav dig en blyertspenna\n";
			blyertspenna = 1;
			grupprummetVal();
	}
	else 
	{
		cout << "-Du gissade fel, du har ett försök kvar. Gissa igen:";
			
		cin >> lekSvar;
			
		if (lekSvar == slumptal)
		{
			cout << "-Snyggt! Du gissade rätt på andra försöket! Här får den en blyertspenna som pris!\nEmil gav dig en blyertspenna\n";
			blyertspenna = 1;
			grupprummetVal();
		}
		else
		{
			cout << "-Du gissade fel två gånger!\n:";
					
			emilVal();	
		}
				
	}
}
void alfredsGåtor()
{

	srand(time(0));//slumptalsgenerator
	int slumptal = (rand() % 14 + 1);
	
	cout << alfredsGåtorText[slumptal];
	string svar;
	getline(cin, svar);


	if (svar == "handduken" || svar == "dammr†ttan" || svar == "trappan" || svar == "klockan" || svar == "solen" || svar == "bron" || svar == "v„gar" || svar == "frim„rket" 
	|| svar == "gropen" || svar == "utsidan" || svar == "s„ngen" || svar == "†ldras" || svar == "skorstenen" || svar == "flaskan" || svar == "ekot")
	{
		cout << "-Det var rätt svar! Här ta denna pennvässaren som pris.\nAlfred gav dig en penvässare./n";
		pennVässare = 1;
		toaletternaVal();
	}
	else
	{
		
		cout << "det var fel svar/n";

		alfredsGåtorVal();
	}
}

//Use PostMessage(wnd, WM_CLOSE, 0, 0) to close the console window, but the problem is probably somewhere else in your program even if this works as a hotfix. The console window should close/disappear automatically when you return from your main() or WinMain().
