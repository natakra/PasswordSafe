# PasswordSafe
PasswordSafe jest projektem realizowanym w ramach zajęć "Indywidualny Projekt Programistyczny" na kierunku Informatyka Stosowana i Systemy Pomiarowe

PasswordSafe to aplikacja służąca do generowania losowych haseł oraz tworzenia spisu kont wraz z hasłami przed użytkownika. Ponadto, umożliwa logowanie się do własnego konta - wiele osób może korzystać na jednym komputerze z tej aplikacji nie nadpisując swoich danych. 

Projekt jest pisany w języku C++, z użyciem IDE QtCreator. 

# UPDATE - 22.03.2020

Spis kont użytkownika będzie przechowywany na dysku. Dane będą zapisywane w bazach danych, które będą odpowiednio szyfrowane, aby użytkownik nie mógł otworzyć ich programem zewnętrznym. 

Przypomnienie hasła - podczas zakładania konta użytkownik zostanie poproszony po odpowiedzenie na pięć losowych pytań (pula pytań będzie bardzo duża, co zmniejszy szansę na powtórzenia). Przywracanie hasła będzie polegało na podaniu odpowiedzi do pytań, cztery poprawne odpowiedzi wystarczą, aby uzyskać dostęp do swojego hasła. Odpowiedzi do pytań będą zabewpieczone w szyfrowanym pliku, aby nikt nie mógł odczytać odpowiedzi otwierając go programem zewnętrznym. 

Użytkownik będzie mógł kontrolować długość wygenerowanego hasła oraz ile haseł chce wygenerować. Dla opcji kilku haseł będzie możliwość zapisania ich w pliku i odczytania później. Dla bezpieczeństwa hasła zawsze będą generowane ze znakami specjalnymi, dużymi i małymi literami oraz cyframi. 

# Raport 2 + Prototyp ( 22.04.2020 )

Praca nad projektem przebiega pomyślnie, większość funkcjonalności zostało już zaimplementowanych. Oto spis wszystkich z nich:
* Użytkownik może założyć konto w aplikacji.
* Użytkownik może zalogować się do aplikacji (przypominanie hasła jeszcze nie jest zaimplementowane).
* Użytkownik może wygenerować unikatowe hasło, z dowolną długością znaków, skopiować je bądź wygenerować wiele haseł do osobnego pliku.
* Użytkownik może dodawać, usuwać i edytować swoją bazę haseł (aby dowiedzieć się co jak działa, należy wcisnąć przycisk "Help").
* Użytkownik może się wylogować oraz zalogować na inne konto.

Do zaimplementowania zostało jeszcze kilka funkcjonalności oraz należy dopracować szatę graficzną aplikacji oraz jej interface. Najważniejsze elementy, które należy dodać to:
* Przypominanie zapominanego hasła.
* Zabezpieczenie baz danych znajdujących się w plikach projektu.


