#include "QTexts.hpp"
#include "GlobFunc.hpp"

QTexts::QTexts()
{
}

QTexts::QTexts(Player * _player)
{
	player = _player;
}

QTexts::~QTexts()
{
}

void QTexts::helper()
{
	cout << "\n\n\tNcisinij dowony klawisz any kontynuowac..." << endl;
	GlobFunc::getch(); GlobFunc::getch();
}

void QTexts::nomore()
{
	setlocale(LC_ALL, "polish");
	cout << "\n\tNie mam dla ciebie wiecej zadani" << endl;
	helper();
}

void QTexts::m1()
{
	setlocale(LC_ALL, "polish");
	cout <<"\n\t"<<player->getName()<< " przybywasz do nowej krainy, ��dny przyg�d s�awy i bogactwa. \n\tNic jednak o niej nie wiesz. Rozejrzy si� po okolicy i dowiedz czego� "<< endl;
	helper();
}

void QTexts::m2()
{
	setlocale(LC_ALL, "polish");
	cout << "\n\tWOJT: Nasza wioska nazywa sie Kurowo. Wioska jak i okoliczne \n\t      ziemie naleza do Lorda Harana, ktory ma swoja siedzibe \n\t      w miescie Arad na polnocny wschod stad." << endl;
	cout << "\t      Nazwa naszej wioski jest nieprzypadkowa. Hodujemy tu \n\t      najlepszy drob, ktroy trafia nawet na krolewskie stoly\n" << endl;
	helper();
}

void QTexts::m3()
{
	setlocale(LC_ALL, "polish");
	cout << "\n\tZnalaz�a by si� jaka� praca dla Ciebie. Kilka dni temu dosz�o do niezwykle \n\tbrutalnego morderstwa. Niestety nie uda�o si� schwyta� sprawcy. \n\tOstatnio widziano go jak pod��a traktem na po�udnie. \n\tPrzynie� mi jego g�ow� a hojnie Ci� wynagrodz�." << endl;
	helper();
}

void QTexts::m4()
{
	setlocale(LC_ALL, "polish");
	cout << "\n\tMam dla Ciebie nowe zadanie:\n\tDochodz� do nas jakie� dziwne plotki o zmar�ych \n\twstaj�cych z grobu. Ci�ko w to wszystko uwierzy�. \n\tP�jd� tam i sprawd� te informacje. " << endl;
	helper();
}

void QTexts::m5()
{
	setlocale(LC_ALL, "polish");
	cout << "\n\t[Pokazujesz ruszaj�ca si� g�ow� trupa] " << endl;
	cout << "\n\tNa bog�w. Co to jest? Cos dziwnego zaczyna si� dzia� w okolicy. Podr�ni i \n\tkupcy przynosz� wie�ci o najmroczniejszy stworach. O wilko�akach, wampirach, nieumar�ych. \n\tMusimy powiadamia� kr�la. Udaj si� na wsch�d, do \n\tkr�lewskiego zamku i pokaz mu ta g�ow�." << endl;
	helper();
}

void QTexts::m6()
{
	setlocale(LC_ALL, "polish");
	cout << "\n\tKr�lu nazywam si� "<<player->getName()<<" przysy�a mnie Lord Arison. Co� niepokoj�cego dzieje si� na jego ziemiach. \n\tZewsz�d dochodz� wie�ci o mrocznych stworzeniach. Na jednym z cmentarzy, spotka�em \n\tkreatur�, do kt�rej nale�a�o to:" << endl;
	cout << "\n\t[pokazujesz �yw� g�ow�]" << endl;
	cout << "\n\tC� za plugastwo. Obawiam si� � �e te same wie�� dochodz� tez i do nas. Malo tego, podobno \n\tgdzie� na polnocnym-wshodzie widziano smoka. Pierwszy raz od tysi�ca lat. To z�y omen. Wie�ci o twojej \n\todwadze i waleczno�ci dosz�o ju� do nas, dlatego prosz� Ci� aby� kontynuowa� to \n\t�ledztwo i rozwik�a dla mnie ta zagadk�. Udaj si� do miasta �wi�tynnego \n\tEram i porozmawiaj najwy�szym kap�anem Heferem. " << endl;
	helper();
}

void QTexts::m7()
{
	setlocale(LC_ALL, "polish");
	cout << "\n\tArcykap�anie, przysy�a mnie kr�l. Widz�, ze dosz�y do was ju� wie�ci o z�u jakie pojawi�o si� w \n\ttej krainie. Wiesz co si� dzieje? Smoki, nieumarli. Sk�d wzi�y si� te plugawe stworzenia? \n\tOczywi�cie, ze ju� dosz�y do nas te straszne wie�ci.Ja i reszta kap�an�w przejrzeli�my wszystkie \n\tstaro�ytne zwoje i okazjo si� ze podoba sytuacja mia�a miejsce w przesz�o�ci.Ponad tysi�c lat temu \n\tpojawi� si� smok z armia mrocznych istot, kt�ra zabija�a wszystko co spotyka�a na drodze.I obawiam \n\tsi� �e nikomu nie uda�o si� ich powstrzyma�.Zapiski m�wi�, �e  po tym jak zgin�o 4 / 3 ludzko�ci \n\tarmia po prostu odesz�a.Wi�cej nie jestem w stanie powiedzie� ale na po�udniu \n\t�yje pewnie czarnoksi�nik, kt�ry mo�e b�dzie wiedzia� cos wi�cej." << endl;
	helper();
}

void QTexts::m8()
{
	setlocale(LC_ALL, "polish");
	cout << "\n\tWitaj. Nazywam si� " << player->getName();
	cout << ". Wiem kim jeste� i domy�lam si� po co tu przyszed�e�. \n\tZapewne ju� arcykap�an opowiedzia� Ci histori� o tym co wydarzy�o si� \n\ttysi�c lat temu. Nie jestem w stanie wiele doda�. No mo�e poza tym, �e to \n\tnie by�a pierwsza taka sytuacja. To dzieje si� cyklicznie co tysi�c \n\tlat i zawsze ko�czy si� tak samo." << endl;
	cout << "\n\t[TY] To niemo�liwe musi by� jaki� spos�b, aby to powstrzyma�." << endl;
	cout << "\n\tJe�eli jakie� informacje mog� si� gdzie� znajdowa�, to tylko w runiach staro�ytnej fortecy. \n\tPodobno ma ona ponad dwa tysi�ce lat. Udaj si� tam i je�eli czego� si� dowiesz wr�� do mnie. " << endl;
	helper();
}

void QTexts::m85()
{
	setlocale(LC_ALL, "polish");
	cout << "\n\tZnalaz�em ten staro�ytny zw�j. Jest napisany w jakim� \n\tdziwnym j�zyku, mo�e ty b�dziesz w stanie go odczyta�?" << endl;
	cout << "\n\t[oddajesz zw�j]" << endl;
	cout << "\n\tHmmm to staro�ytne pismo, ale na szcz�cie jeszcze nie ca�kiem zapominanie.\n\tDaj mi chwile a b�d� w stanie je odczyta�." << std::endl;
	cout << "\n\t[po chwili]" << std::endl;
	cout << "\n\tTu jest napisane, �e da si� powstrzyma� mroczn� armie.Trzeba zabi� smoka \n\tprzyw�dc�, zwanego �niwiarzem, kt�rego aura przyci�ga te stworzenia.Smok \n\tnabiera mocy z czasem i gry osi�gnie pe�nie mocy jego armia rusza i zbiera \n\t�niwo z �y� ludzi.Teraz jest jeszcze s�aby.Niedawno musia� si� przebudzi�, mimo to \n\tnie mo�na go zabi� tak po prostu.Podobno na p�nocy, w labiryncie znajduje si� \n\tor� zes�any od bog�w i tylko on jest wstanie zabi�.Przydatna mo�e by� te� \n\tzbroja Faruman, dawnego kr�la pochowanego w Piramidzie na wsch�d stad. Zapiski \n\tm�wi� ze zosta�a wykuta z kamienia kt�ry spad� z niema i za hartowaniu sta�a si� \n\tniezwykle twarda.Udaj si� wice w te miejsca, zdob�d� te przedmioty po czym \n\twr�� do mnie." << std::endl;
	helper();
}

void QTexts::m9()
{
	setlocale(LC_ALL, "polish");
	cout << "\n\tUda�o Ci si� zdoby� te artefakty? Niesamowite. Mo�e jest jeszcze nadzieja. Nie zosta�o \n\tCi ju� nic innego jak przyst�pi� do ostatecznej walki. Wr�� jeszcze do kr�la i opowiedz mu o \n\twszystkim, mo�e Ci� jako� nagrodzi. " << endl;
	helper();
}

void QTexts::m10()
{
	setlocale(LC_ALL, "polish");
	cout << "\n\tWitaj krol. Mam wie�ci. " << endl;
	cout << "\n\t[Opowiadasz o wszystkim] " << endl;
	cout << "\n\tTo niesamowita historia. A wi�c ca�a nadzieja w Tobie. Je�eli zawiedziesz, to wszyscy zginiemy. \n\tKarze zaraz Ci� wynagrodzi�. Kup wszystko co Ci b�dzie potrzebne i ocal nas. Udaj si� \n\tjeszcze do �wi�tyni w Eram niech Arcykap�an Ci� pob�ogos�awi. Ja tymczasem \n\tkarze spisa�, to wszystko co powiedzia�e� dla potomnych, w razie jakby Ci si� jednak nie uda�o.  " << endl;
	helper();
}

void QTexts::m11()
{
	setlocale(LC_ALL, "polish");
	cout << "\n\tWitaj ponownie " << player->getName() << endl;
	cout << "\n\tCzekali�my na Ciebie. Go�cy ju� przys�ali list od kr�la, w kt�rym wszystko wyja�ni�. ";
	cout << "\n\t[B�ogos�awi]";
	cout << "\n\tNiech bogowie b�d� z tob� i niech rozja�ni� Ci drog� przez ciemno��." << endl;
	helper();
}

void QTexts::m12()
{
	setlocale(LC_ALL, "polish");
	cout << "n\tPokona�e� smoka �niwiarza, a jego armia odesz�a w raz z nim w otch�a�. Ty sta�e� si� bohatera, a kr�l nada� Ci ziemie i tytu�. " << endl;
	cout << "\n\n\n\t\tTHE END" << endl;
	helper();
	GlobFunc::clearScreean();
	cout << "\n\n\t\tAutor: Piotr Konicki" << endl;
	helper();
}

void QTexts::kur1()
{
	setlocale(LC_ALL, "polish");
	cout << "\n\tTak. Na drodze do miasta jaki� �otr zasadza si� na \n\tch�op�w id�cych do miasta. Zastrasza ich i wymusza okop za przej�cie. \n\tPozb�d� si� go prosz� bo nie daje nam �y�." << endl;
}

void QTexts::kur2()
{
	setlocale(LC_ALL, "polish");
	cout << "\n\tTak. Mamy problem z wilkiem. Od miesi�cy co jaki� czas \n\tzabija, kt�remu� z ch�op�w owce, a raz nawet i dziecko rozszarpa� \n\tUwolnij nas od tej bestii a Ci� nagrodzimy tym co nam jeszcze zosta�o" << endl;
}

void QTexts::kur3()
{
	setlocale(LC_ALL, "polish");
	cout << "\n\tTak. Budujemy nowy spichlerz i zabrak�o nam gwo�dzi.\n\tJakby� by� w mie�cie, to kup nam gwo�dzie. \n\tOdwdzi�czymy si� za fatyg�" << endl;
}

void QTexts::arad1()
{
	setlocale(LC_ALL, "polish");
	cout << "\n\tS�ysza�em, �e na po�udniowy wsch�d st�d widziano jakiego� orka. Orkowe to \n\tdobrzy wojownicy lubi�cy mordowa�, ale tez �wietnie znaj� si� na \n\tobr�bce metali. Nie zdziwi�bym si� jakby mia� przy sobie jak�� dobra bro�.";
	helper();
}

void QTexts::arad2()
{
	setlocale(LC_ALL, "polish");
	cout << "\n\tObieca�em karczmarzowi z Eram, �e przy�le mu paczk� przypraw, kt�re \n\tpoprawia smak jego piwa. Zanie� mu t� paczek a na pewno hojnie Ci� wynagrodzi";
}

void QTexts::castle2()
{
	setlocale(LC_ALL, "polish");
	cout << "\n\tNa dalekiej p�nocy znajduje si� wie�a, kt�ra nale�a�a do jednego z \n\tdawnych rod�w. Po tym jak osta� Lord zgina w bitwie, wie�a zacz�a \n\tpodupada�, a w �rodku zadomowi�y si� harpie. M�wi si�, �e maj�tek rodu \n\tnigdy nie zosta� zabrany z wie�y. " << endl;
	helper();
}

void QTexts::castle1()
{
	setlocale(LC_ALL, "polish");
	cout << "\n\tW kr�lewskim borze na p�nocnym-zachodzie zgin�o juz 5 kr�lewskich \n\tmy�liwych. Ich cia�a znaleziono rozszarpane w obozie nast�pnego dnia. Niekt�rzy \n\tm�wi� ze to wilko�ak. I faktycznie w nocy kiedy zginali by�a pe�nia. \n\tZajmiesz si� tym?" << endl;
}

void QTexts::eram()
{
	setlocale(LC_ALL, "polish");
	cout << "\n\tDaleko na p�nocnym-zachodzie grasuje troll. Napasa na podr�nych i kupc�w. \n\tCi kt�rzy prze�yli m�wi�, �e ju� nigdy tu nie przyb�d� ponownie. Ten troll nie tylko zagra�a \n\tludziom, ale tez handlowi ze wschodnimi kr�lestwami. Pozb�d� si� go, a wszystko co \n\tznajdziesz przy nim b�dziesz m�g� zatrzyma� i dodatkowo dostaniesz troche z�ota ode mnie. \n\tA z tego co wiem, trolle lub� b�yszcz�ce rzeczy. " << endl;
}

void QTexts::hadi()
{
	setlocale(LC_ALL, "polish");
	cout << "\n\tPanie, " << player->getName()<<" ratuj nas.W okolicy grasuje wampir i od miesi�ca raz w tygodniu \n\tzabija jednego mieszka�ca nasz wioski.Ju� cztery martwe osoby znale�li�my i �adna nie \n\tmaila w sobie ani kropli krwi.Na po�udnie stad znajduje si� stare cmentarzysko. \n\tMysle ze tam mo�e mie� swoj� siedzib�" << endl;
}
