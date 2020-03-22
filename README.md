# PasswordSafe
PasswordSafe jest projektem realizowanym w ramach zajęć "Indywidualny Projekt Programistyczny" na kierunku Informatyka Stosowana i Systemy Pomiarowe

PasswordSafe to aplikacja służąca do generowania losowych haseł oraz tworzenia spisu kont wraz z hasłami przed użytkownika. Ponadto, umożliwa logowanie się do własnego konta - wiele osób może korzystać na jednym komputerze z tej aplikacji nie nadpisując swoich danych. 

Projekt jest pisany w języku C++, z użyciem IDE QtCreator. 

# UPDATE - 22.03.2020

Spis kont użytkownika będzie przechowywany na dysku. Dane będą zapisywane w bazach danych, które będą odpowiednio szyfrowane, aby użytkownik nie mógł otworzyć ich programem zewnętrznym. 

Przypomnienie hasła - podczas zakładania konta użytkownik zostanie poproszony po odpowiedzenie na pięć losowych pytań (pula pytań będzie bardzo duża, co zmniejszy szansę na powtórzenia). Przywracanie hasła będzie polegało na podaniu odpowiedzi do pytań, cztery poprawne odpowiedzi wystarczą, aby uzyskać dostęp do swojego hasła. Odpowiedzi do pytań będą zabewpieczone w szyfrowanym pliku, aby nikt nie mógł odczytać odpowiedzi otwierając go programem zewnętrznym. 

Użytkownik będzie mógł kontrolować długość wygenerowanego hasła oraz ile haseł chce wygenerować. Dla opcji kilku haseł będzie możliwość zapisania ich w pliku i odczytania później. Dla bezpieczeństwa hasła zawsze będą generowane ze znakami specjalnymi, dużymi i małymi literami oraz cyframi. 
