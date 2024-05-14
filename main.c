import time
import random

file = open("story.txt", "w", encoding="utf-8")


# функция, которая запрашивает имя героя
# приключение начинается именно с нее
def start_history():
    # выводится вступительный текст приключения и запрашивается выбор персонажа.
    print(
        "Глубоко в городе Хокинс, где обычные дни омрачены тайнами и странными событиями, живет Майк - обычный "
        "подросток с необычным жизненным опытом. \n "
        "Он и его друзья привыкли к опасным приключениям, которые их ждут за каждым поворотом.\n"
        "Сегодняшний день начался обычно, но вскоре Майк получил звонок, который заставил его сердце замирать от "
        "тревоги. Звонил отец мальчика, чей сын исчез. Что-то темное, неопределенное и ужасное, пугавшее его сына, "
        "зашло к его дому. На Майке и его друзьях снова лежит тяжелая ответственность распутать новую загадку.\n "
        "Путешествие в мире странных и удивительных событий начинается, и вам предстоит принять участие в этом "
        "невероятном приключении.\n")
    file.write(
        "Глубоко в городе Хокинс, где обычные дни омрачены тайнами и странными событиями, живет Майк - обычный"
        "подросток с необычным жизненным опытом.\n"
        "Он и его друзья привыкли к опасным приключениям, которые их ждут за каждым поворотом.\n"
        "Сегодняшний день начался обычно, но вскоре Майк получил звонок, который заставил его сердце замирать от"
        "тревоги. Звонил отец мальчика, чей сын исчез. Что-то темное, неопределенное и ужасное, пугавшее его сына,"
        "зашло к его дому. На Майке и его друзьях снова лежит тяжелая ответственность распутать новую загадку.\n"
        "Путешествие в мире странных и удивительных событий начинается, и вам предстоит принять участие в этом"
        "невероятном приключении.\n")
    # слвоарь для хранения имен героев и их описания
    characters_info = {
        'Майк': 'Главный герой истории, обычный подросток с необычным жизненным опытом.',
        'Уилл': 'Лучший друг Майка, исчез после таинственного появления странных существ в городе.',
        'Стив': 'Старший брат одного из друзей Майка, всегда оказывается в нужное время в нужном месте',
        'Дастин': 'Один из друзей Майка, увлекается наукой и техникой, всегда готов помочь в решении загадок.',
        'Лукас': 'Еще один друг Майка, отличается решительностью и отвагой в трудных ситуациях.'
    }
    print_character_info(characters_info)

    time.sleep(2)
    while True:
        name = input("\nВыберите персонажа, за которого вы хотите играть: ")
        file.write("Выберите персонажа, за которого вы хотите играть: \n")
        file.write(name)
        file.write("\n")
        if name in characters_info:
            print(f"Приветствую тебя, {name}.\n")
            file.write(f"Приветствую тебя, {name}.\n")
            break
        # если имени, которое ввел пользователь, нет в списке,
        # то просим пользователя заново ввести имя игрока
        else:
            print("Неверное имя персонажа. Попробуйте еще раз:")
            file.write("Неверное имя персонажа. Попробуйте еще раз:")
    return name


# Функция для вывода информации о персонажах
def print_character_info(characters_info):
    print("Информация о персонажах:")
    for name, info in characters_info.items():
        print(f"{name}: {info}")
        file.write(f"{name}: {info}\n")


# эта функция описывает ситуацию, где герой стоит перед выбором
# в зависимости от выбора игрока вызываются соответствующие функции.
def magic_house(name):
    time.sleep(1.5)
    print(f"{name}, решивший взять на себя роль главного героя, стоит перед первым важным выбором. \n"
          f"Он может решить начать расследование собственными силами, отправившись к дому пропавшего ребенка \n"
          f"или же обратиться к местным жителям и полиции за помощью и дополнительной информацией.")
    file.write(f"{name}, решивший взять на себя роль главного героя, стоит перед первым важным выбором.\n"
               f"Он может решить начать расследование собственными силами, отправившись к дому пропавшего ребенка\n"
               f"или же обратиться к местным жителям и полиции за помощью и дополнительной информацией.\n")
    time.sleep(2)
    print(f"\nЕсли {name} решит отправиться к дому пропавшего ребенка, нажмите 1\n"
          f"Если {name} предпочтет обратиться к местным жителям или полиции, нажмите 2")
    file.write(f"\nЕсли {name} решит отправиться к дому пропавшего ребенка, нажмите 1\n"
               f"Если {name} предпочтет обратиться к местным жителям или полиции, нажмите 2\n")
    time.sleep(2)
    while True:
        try:
            # пользователю предлагается выбрать одно из двух действий и проверяется корректность выбора.
            decision = int(input(f"Выбор за вами, {name}. Куда направимся в первую очередь?:  "))
            file.write(f"Выбор за вами, {name}. Куда направимся в первую очередь?: ")
            file.write(str(decision))
            file.write("\n")
            if decision == 1:
                solo_wanderings(name)
                break
            elif decision == 2:
                police_assistance(name)
                break
            else:
                print("Неверный выбор. Пожалуйста, выберите 1 или 2.")
                file.write("Неверный выбор. Пожалуйста, выберите 1 или 2.")
        # здесь происходит обработка ошибок при неверном вводе
        # например, если введены буквы
        except ValueError:
            print("Неверный ввод. Пожалуйста, введите число.")
            file.write("Неверный ввод. Пожалуйста, введите число.")


# описываются действия героя, если он обратился за помощью к полиции.
def police_assistance(name):
    print(f"{name} решил обратиться к местным жителям и полиции за помощью.")
    file.write(f"{name} решил обратиться к местным жителям и полиции за помощью.\n")
    time.sleep(2)
    print(
        f"Собрав информацию от местных жителей, {name} выяснил, что дом пропавшего ребенка находится в глухой части "
        f"города.")
    file.write(
        f"Собрав информацию от местных жителей, {name} выяснил, что дом пропавшего ребенка находится в глухой части "
        f"города.\n")
    time.sleep(2)
    print(f"Прибыв на место вместе с полицией, {name} видит, что дом пуст и кажется заброшенным.")
    file.write(f"Прибыв на место вместе с полицией, {name} видит, что дом пуст и кажется заброшенным.\n")
    time.sleep(2)
    print(f"Полиция начинает расследование, а {name} решает осмотреть окрестности в поисках каких-либо улик.")
    file.write(
        f"Полиция начинает расследование, а {name} решает осмотреть окрестности в поисках каких-либо улик.\n")
    time.sleep(2)
    print(f"Во время поисков {name} натыкается на странный след, который, кажется, ведет в глубь леса.")
    file.write(f"Во время поисков {name} натыкается на странный след, который, кажется, ведет в глубь леса.\n")
    time.sleep(2)
    print("Что сделаете дальше?")
    file.write("Что сделаете дальше?\n")
    time.sleep(1)
    while True:
        try:
            print("1. Следовать по следам\n"
                  "2. Вернуться к дому и продолжить расследование внутри")
            file.write("1. Следовать по следам\n"
                       "2. Вернуться к дому и продолжить расследование внутри")
            decision = int(input("Выберите действие: "))
            file.write("Выберите действие: ")
            file.write(str(decision))
            file.write("\n")
            if decision == 1:
                go_into_the_woods(name)
                break
            elif decision == 2:
                follow_up(name)
                break
            else:
                print("Неверный выбор. Пожалуйста, выберите 1 или 2.")
                file.write("Неверный выбор. Пожалуйста, выберите 1 или 2.\n")
        except ValueError:
            print("Неверный ввод. Пожалуйста, введите число.")
            file.write("Неверный ввод. Пожалуйста, введите число.\n")


# описываются действия героя, если он отправляется в лес.
def go_into_the_woods(name):
    print(f"{name} решает отправиться в лес, следуя за странным следом.")
    file.write(f"{name} решает отправиться в лес, следуя за странным следом.\n")
    time.sleep(2)
    print("Погружаясь в глубины леса, окружающий мир начинает меняться.")
    file.write("Погружаясь в глубины леса, окружающий мир начинает меняться.\n")
    time.sleep(2)
    print("Деревья становятся плотнее, шумы становятся загадочнее, а атмосфера наполняется тайной.")
    file.write("Деревья становятся плотнее, шумы становятся загадочнее, а атмосфера наполняется тайной.\n")
    time.sleep(2)
    print(f"В конце концов {name} приходит к странной поляне, где видит... ")
    file.write(f"В конце концов {name} приходит к странной поляне, где видит...\n")
    found_item = random.choice(["мистический артефакт", "деревянная фигурка", "странная книга"])
    print(f"{name} обнаруживает...")
    file.write(f"{name} обнаруживает...\n")
    time.sleep(2)
    print(f"{found_item}! Ого! - подумал {name}")
    file.write(f"{found_item}! Ого! - подумал {name}\n")
    print(f"Что же сделаете дальше, возьмет ли {name} этот предмет?")
    file.write(f"Что же сделаете дальше, возьмет ли {name} этот предмет?\n")
    while True:
        decision = input("1. Взять предмет\n2. Оставить его и продолжить исследование\nВыберите вариант: ")
        file.write("1. Взять предмет\n2. Оставить его и продолжить исследование\nВыберите вариант: ")
        file.write(str(decision))
        file.write("\n")
        if decision == "1":
            # герой решает взять предмет
            print(f"{name}, {found_item} теперь с тобой!")
            file.write(f"{name}, {found_item} теперь с тобой!")
            end_story(name, found_item)
            break
        elif decision == "2":
            # герой решает не брать предмет
            print(f"{name} решает не брать этот предмет и продолжает исследование леса...")
            file.write(f"{name} решает не брать этот предмет и продолжает исследование леса...")
            continue_story(name)
            break
        else:
            print("Пожалуйста, выберите 1 или 2.")
            file.write("Пожалуйста, выберите 1 или 2.")


def follow_up(name):
    print(f"{name} решает следовать за чем-то еще.")
    file.write(f"{name} решает следовать за чем-то еще.")
    time.sleep(2)
    print("Внезапно перед ним появляется странный шум.")
    file.write("Внезапно перед ним появляется странный шум.")
    time.sleep(2)
    print("Шум напоминает шорох листьев, но он звучит как-то... неестественно.")
    file.write("Шум напоминает шорох листьев, но он звучит как-то... неестественно.")
    time.sleep(2)
    print(f"Решив не упустить возможность, {name} принимает решение следовать за звуком.")
    file.write(f"Решив не упустить возможность, {name} принимает решение следовать за звуком.\n")
    time.sleep(3)
    print(f"Через несколько минут {name} выходит на неожиданную поляну.")
    file.write(f"Через несколько минут {name} выходит на неожиданную поляну.\n")
    # это множество строк, среди которых выбирается рандомным образом одна
    found_item = random.choice(["загадочный артефакт", "старинный клад", "заколдованный камень"])
    print(f"{name} обнаруживает {found_item}!")
    file.write(f"{name} обнаруживает {found_item}!\n")
    time.sleep(2)
    print(f"Что же сделаете дальше, возьмете ли {found_item}?")
    file.write(f"Что же сделаете дальше, возьмете ли {found_item}?\n")
    while True:
        decision = input("1. Взять предмет\n2. Оставить его и идти дальше\nВыберите вариант: ")
        file.write("1. Взять предмет\n2. Оставить его и идти дальше\nВыберите вариант: " + str(decision) + "\n")
        if decision == "1":
            print(f"{name}, {found_item} теперь с тобой!")
            file.write(f"{name}, {found_item} теперь с тобой!\n")
            end_story(name, found_item)
            break
        elif decision == "2":
            print(f"{name} решает не брать {found_item} и продолжает исследование поляны...")
            file.write(f"{name} решает не брать {found_item} и продолжает исследование поляны...\n")
            continue_story(name)
            break
        else:
            print("Пожалуйста, выберите 1 или 2.")
            file.write("Пожалуйста, выберите 1 или 2.")


def continue_story(name):
    time.sleep(2)
    print(f"Внезапно перед {name}ом возникает огромная птица с крыльями в два раза больше человеческого роста.")
    file.write(f"Внезапно перед {name}ом возникает огромная птица с крыльями в два раза больше человеческого роста.\n")
    time.sleep(2)
    print(f"Она приносит {name}у загадочное письмо и исчезает в воздухе.")
    file.write(f"Она приносит {name}у загадочное письмо и исчезает в воздухе.\n")
    time.sleep(2)
    print(f"Письмо гласит: 'Ты совершил ошибку, оставив предмет. Теперь мы заберем его сами.'")
    file.write(f"Письмо гласит: 'Ты совершил ошибку, оставив предмет. Теперь мы заберем его сами.'\n")
    time.sleep(2)
    print(f"Внезапно {name} чувствует, что его поднимают в воздух, и он теряет сознание...")
    file.write(f"Внезапно {name} чувствует, что его поднимают в воздух, и он теряет сознание...\n")
    time.sleep(2)
    # завершение истории
    print(f"Игра завершена. Благодарим вас, {name}, за участие в этой захватывающей истории!")
    file.write(f"Игра завершена. Благодарим вас, {name}, за участие в этой захватывающей истории!\n")


# завершение истории с успешным исходом
def end_story(name, found_item):
    print(f"Оказалось, что {found_item} и есть тот самый ключ к расследованию дела")
    file.write(f"Оказалось, что {found_item} и есть тот самый ключ к расследованию дела\n")
    print(f"{name}, тебе повезло, что ты взял этот предмет тогда в лесу")
    file.write(f"{name}, тебе повезло, что ты взял этот предмет тогда в лесу\n")
    time.sleep(3)
    print(".........  ДЕНЬ СПУСТЯ  ..........\n\n")
    file.write(".........  ДЕНЬ СПУСТЯ  ..........\n\n")
    time.sleep(3)
    print(f"{name} и его друзья наконец-то находят пропавшего ребенка.")
    file.write(f"{name} и его друзья наконец-то находят пропавшего ребенка.\n")
    time.sleep(2)
    print(f"Благодаря расследованию {name}а, ребенок был найден невредимым и в полном здравии.")
    file.write(f"Благодаря расследованию {name}а, ребенок был найден невредимым и в полном здравии.\n")
    time.sleep(2)
    print("Все смогли вернуться домой, чувствуя облегчение.")
    file.write("Все смогли вернуться домой, чувствуя облегчение.\n")
    time.sleep(2)
    print(f"Приключение завершено. Благодарим вас, {name}, за участие в этой захватывающей истории!")
    file.write(f"Приключение завершено. Благодарим вас, {name}, за участие в этой захватывающей истории!\n")


# действия героя, если он решает подождать.
def wait_and_watch(name):
    print(f"{name} решает остановиться и подождать, чтобы рассмотреть, кто это.")
    file.write(f"{name} решает остановиться и подождать, чтобы рассмотреть, кто это.\n")
    time.sleep(2)
    print(f"Тень приближается, и {name} начинает различать очертания существа.")
    file.write(f"Тень приближается, и {name} начинает различать очертания существа.\n")
    time.sleep(2)
    print("Внезапно перед ним появляется странное существо - высокий силуэт, излучающий таинственный свет.")
    file.write("Внезапно перед ним появляется странное существо - высокий силуэт, излучающий таинственный свет.\n")
    time.sleep(2)
    print("Оно медленно приближается, но не выглядит враждебным.")
    file.write("Оно медленно приближается, но не выглядит враждебным.\n")
    time.sleep(2)
    print(f"Кажется, что {name} стоит перед неким существом из иного мира, но оно не кажется опасным.")
    file.write(f"Кажется, что {name} стоит перед неким существом из иного мира, но оно не кажется опасным.\n")
    time.sleep(2)
    print(
        f"Существо произносит его имя и рассказывает {name}y о том, что ребенка похитили странные существа из другого "
        f"измерения.")
    file.write(
        f"Существо произносит его имя и рассказывает {name}y о том, что ребенка похитили странные существа из другого "
        f"измерения.\n")
    time.sleep(2)
    while True:
        try:
            decision = int(input(f"Выбор за вами, {name}\n 1. Открыть портал\n"
                                 "2. Бежать как можно скорее обратно\n"
                                 "3. Попытаться установить контакт с существом,"
                                 "Что ты выберешь? "))
            file.write(f"Выбор за вами, {name}\n 1. Открыть портал\n"
                                 "2. Бежать как можно скорее обратно\n"
                                 "3. Попытаться установить контакт с существом,"
                                 "Что ты выберешь? ")
            file.write(str(decision))
            if decision == 1 or decision == 3:
                if decision == 3:
                    print("Существо помогло тебе найти ключ к открыванию портала")
                    file.write("Существо помогло тебе найти ключ к открыванию портала\n")
                open_a_portal(name)
                break
            elif decision == 2:
                creature_escape(name)
                break
            else:
                print("Неверный выбор. Пожалуйста, выберите 1 или 2.")
                file.write("Неверный выбор. Пожалуйста, выберите 1 или 2.\n")
        except ValueError:
            print("Неверный ввод. Пожалуйста, введите число.")
            file.write("Неверный ввод. Пожалуйста, введите число.\n")


# действия героя, если он пытается убежать от существа.
def creature_escape(name):
    print(f"{name} решает попытаться убежать от существа.")
    file.write(f"{name} решает попытаться убежать от существа.\n")
    time.sleep(2)
    print("Он начинает бежать, но чувствует, что существо приближается всё быстрее.")
    file.write("Он начинает бежать, но чувствует, что существо приближается всё быстрее.\n")
    time.sleep(2)
    print(f"Видя, что он не сможет убежать от существа, {name} решает открыть портал, чтобы уйти.")
    file.write(f"Видя, что он не сможет убежать от существа, {name} решает открыть портал, чтобы уйти.\n")
    time.sleep(2)
    print("Он быстро изучает устройство, которое взял с собой и в последний момент открывает портал.")
    file.write("Он быстро изучает устройство, которое взял с собой и в последний момент открывает портал.\n")
    time.sleep(2)
    print("Обратный отсчет начинается...")
    file.write("Обратный отсчет начинается...\n")
    time.sleep(2)
    # цикл, который имитирует обратный отсчет до открытия портала
    # с помощью него накаляется атмосфера и создается эффект ожидания
    for i in range(5, 0, -1):
        print(i)
        file.write(str(i))
        file.write("\n")
        time.sleep(1.4)
    # цикл, который имитирует взрывы при открытиии портала
    for _ in range(0, 10):
        print("BOOM!")
        file.write("BOOM!")
        file.write("\n")
        time.sleep(0.1)
    time.sleep(1.5)
    print(f"Существо достигает {name}a и атакует его!")
    file.write(f"Существо достигает {name}a и атакует его!\n")
    time.sleep(2)
    print(f"Увы, {name} падает, потерпев поражение...")
    file.write(f"Увы, {name} падает, потерпев поражение...\n")
    time.sleep(2)
    print("Приключение завершено. Неудачный конец...")
    file.write("Приключение завершено. Неудачный конец...\n")
    time.sleep(2)
    print(f"История о приключениях {name}a и его друзей завершилась...")
    # приключение завершилось с неудачным концом
    file.write(f"История о приключениях {name}a и его друзей завершилась...\n")


# герой решает открыть портал и спасти ребенка.
def open_a_portal(name):
    print(f"Вы очень смелый, {name}, и открываете портал")
    file.write(f"Вы очень смелый, {name}, и открываете портал\n")
    print("Обратный отсчет пошел...Назад дороги нет...")
    file.write("Обратный отсчет пошел...Назад дороги нет...\n")
    time.sleep(1.5)

    for i in range(5, 0, -1):
        print(i)
        file.write(str(i))
        file.write("\n")
        time.sleep(1.4)
    for _ in range(0, 10):
        print("BOOM!")
        file.write("BOOM!")
        file.write("\n")
        time.sleep(0.15)
    time.sleep(1.5)
    print("Вы открываете портал в другое измерение, спасая при этом ребенка, и помогаете ему вернуться домой.")
    file.write("Вы открываете портал в другое измерение, спасая при этом ребенка, и помогаете ему вернуться домой.\n")
    time.sleep(2)
    print(f"{name} становится героем Хокинса и сохраняет мир от неведомой опасности.")
    file.write(f"{name} становится героем Хокинса и сохраняет мир от неведомой опасности.\n")
    time.sleep(2)
    # приключение заканчивается благополучно
    print(f"Приключение завершено. История о приключениях {name}a и его друзей продолжится...")
    file.write(f"Приключение завершено. История о приключениях {name}a и его друзей продолжится...\n")


def try_to_escape(name):
    print(f"{name} решает ускориться, чтобы попытаться уйти от опасности.")
    file.write(f"{name} решает ускориться, чтобы попытаться уйти от опасности.\n")
    time.sleep(2)
    print(f"Пока {name} бежал к дому пропавшего ребенка, он ощущал, что его преследуют.")
    file.write(f"Пока {name} бежал к дому пропавшего ребенка, он ощущал, что его преследуют.\n")
    time.sleep(2)
    print("Вдруг он разворачивается и видит, что это огромное существо с темными, бесформенными обликами.")
    file.write("Вдруг он разворачивается и видит, что это огромное существо с темными, бесформенными обликами.\n")
    time.sleep(2)

    while True:
        try:
            decision = int(
                input("Что вы хотите сделать?\n1 - продолжить бежать\n2 - остановиться и попытаться спрятаться: "))
            file.write("Что вы хотите сделать?\n1 - продолжить бежать\n2 - остановиться и попытаться спрятаться: ")
            file.write(str(decision) + "\n")
            if decision == 1:
                continue_running(name)
                break
            elif decision == 2:
                hide_and_wait(name)
                break
            else:
                print("Неверный выбор. Пожалуйста, выберите 1 или 2.")
                file.write("Неверный выбор. Пожалуйста, выберите 1 или 2.\n")
        except ValueError:
            print("Неверный ввод. Пожалуйста, введите число.")
            file.write("Неверный ввод. Пожалуйста, введите число.\n")


def continue_running(name):
    print(f"Оно стремительно приближается, и {name} понимает, что у него нет шансов убежать.")
    time.sleep(2)
    print("Внезапно перед ним появляется странный свет, и существо замирает.")
    time.sleep(2)
    print(
        f"{name} видит, что это его друзья, пришедшие на помощь. Они использовали особое устройство, чтобы остановить "
        f"существо.")
    time.sleep(2)
    print("Спасая вас, они оказывают сопротивление существу, пока вы убегаете в дом.")
    time.sleep(2)
    print(f"Вместе с друзьями {name} удается закрыть дверь")
    time.sleep(2)
    print("Подойдя к окну, вы видите, как существо исчезает в темноте.")
    time.sleep(2)
    print(f"Тяжело дыша, {name} понимает, что они едва выжили.")
    time.sleep(2)
    print(f"Приключение завершено. История о приключениях {name}a и его друзей продолжится...")
    file.write(f"Оно стремительно приближается, и {name} понимает, что у него нет шансов убежать.\n")
    file.write("Внезапно перед ним появляется странный свет, и существо замирает.\n")
    file.write(
        f"{name} видит, что это его друзья, пришедшие на помощь. Они использовали особое устройство, чтобы остановить "
        f"существо.\n")
    file.write("Спасая вас, они оказывают сопротивление существу, пока вы убегаете в дом.\n")
    file.write(f"Вместе с друзьями {name} удается закрыть дверь\n")
    file.write("Подойдя к окну, вы видите, как существо исчезает в темноте.\n")
    file.write(f"Тяжело дыша, {name} понимает, что они едва выжили.\n")
    file.write(f"Приключение завершено. История о приключениях {name}a и его друзей продолжится...\n")


def hide_and_wait(name):
    print(f"{name} решает остановиться и попытаться спрятаться.")
    file.write(f"{name} решает остановиться и попытаться спрятаться.\n")
    time.sleep(2)
    print("Существо приближается, и вы чувствуете, как ваше сердце бьется в ушах.")
    file.write("Существо приближается, и вы чувствуете, как ваше сердце бьется в ушах.\n")
    time.sleep(2)
    print(f"Оно проходит мимо, и {name} слышит, как оно исчезает в темноте.")
    file.write(f"Оно проходит мимо, и {name} слышит, как оно исчезает в темноте.\n")
    time.sleep(2)
    print("После того как убежище становится тихим, вы выходите из укрытия и бежите в дом.")
    file.write("После того как убежище становится тихим, вы выходите из укрытия и бежите в дом.\n")
    time.sleep(2)
    print("Но существо не ушло...")
    file.write("Но существо не ушло...\n")
    continue_running(name)


# описываются действия героя , если он решил пойти в одиночку
def solo_wanderings(name):
    print(f"Конечно, {name} решил не обращаться за помощью.")
    file.write(f"Конечно, {name} решил не обращаться за помощью.\n")
    time.sleep(2)
    print(f"Он решил поехать на велосипеде. На улице шел проливной дождь, но {name} не сдавался.")
    file.write(f"Он решил поехать на велосипеде. На улице шел проливной дождь, но {name} не сдавался.\n")
    time.sleep(2)
    print(f"Подъезжая к дому пропавшего ребенка, {name} замечает что-то странное.")
    file.write(f"Подъезжая к дому пропавшего ребенка, {name} замечает что-то странное.\n")
    time.sleep(2)
    print("На улице почти никого нет, но издали он замечает тень, двигающуюся в сторону дома.")
    file.write("На улице почти никого нет, но издали он замечает тень, двигающуюся в сторону дома.\n")
    time.sleep(2)
    print("Его сердце начинает биться сильнее, и он осознает, что находится в опасности.")
    file.write("Его сердце начинает биться сильнее, и он осознает, что находится в опасности.\n")
    time.sleep(2)
    print(f"Что будет делать {name}?\n")
    file.write(f"Что будет делать {name}?\n")
    time.sleep(1)
    print("1. Остановиться и подождать, чтобы рассмотреть, кто это.\n"
          "2. Ускориться, чтобы попытаться уйти от опасности.")
    file.write("1. Остановиться и подождать, чтобы рассмотреть, кто это.\n"
               "2. Ускориться, чтобы попытаться уйти от опасности.\n")
    while True:
        try:
            decision = int(input("Выберите действие: "))
            file.write("Выберите действие: " + str(decision) + "\n")
            if decision == 1:
                wait_and_watch(name)
                break
            elif decision == 2:
                try_to_escape(name)
                break
            else:
                print("Неверный выбор. Пожалуйста, выберите 1 или 2.")
                file.write("Неверный выбор. Пожалуйста, выберите 1 или 2.\n")
        except ValueError:
            print("Неверный ввод. Пожалуйста, введите число.")
            file.write("Неверный ввод. Пожалуйста, введите число.\n")


# вся история происходит из этой функции
def entrance_to_history():
    # запрашиваем имя игрока, за которого хочет играть пользователь
    # чтобы в дальнейшем использовать его в других функциях
    name = start_history()
    # с помощью функции time.sleep создаем эффект ожидания и настоящей истории
    time.sleep(2)
    # история начинается с поездки в магический дом
    magic_house(name)


entrance_to_history()

