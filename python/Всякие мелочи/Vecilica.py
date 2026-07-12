import turtle

word = 'волос'

# Черепашка для человечка
t = turtle.Turtle()
t.speed(3)
t.penup()
t.goto(0, 100)
t.hideturtle()

# Черепашка для букв
draw = turtle.Turtle()
draw.speed(0)
draw.hideturtle()

def draw_body_part(part):
    t.pendown()
    if part == "head":
        t.circle(20)
    elif part == "body":
        t.right(90)
        t.forward(70)
    elif part == "left_arm":
        t.backward(70)
        t.left(45)
        t.forward(40)
        t.backward(40)
        t.right(45)
    elif part == "right_arm":
        t.right(45)
        t.forward(40)
        t.backward(40)
        t.left(45)
        t.forward(70)
    elif part == "left_leg":
        t.left(45)
        t.forward(50)
        t.backward(50)
        t.right(45)
    elif part == "right_leg":
        t.right(45)
        t.forward(50)
    t.penup()

# Части тела
parts = ["head", "body", "left_arm", "right_arm", "left_leg", "right_leg"]

# Рисуем подчёркивания
for i in range(len(word)):
    draw.penup()
    draw.goto(-100 + i * 40, -150)
    draw.pendown()
    draw.write('_', align='center', font=('Arial', 30, 'normal'))

guessed = ''
wrong = ''

print(f"Угадай слово из {len(word)} букв!")

while True:
    # Проверка победы
    won = True
    for letter in word:
        if letter not in guessed:
            won = False
    if won:
        print("Вы выиграли!")
        break
    
    letter = input('Буква: ')
    
    if len(letter) != 1:
        print('Одна буква!')
        continue
    
    if letter in guessed or letter in wrong:
        print('Уже было!')
        continue
    
    if letter in word:
        guessed += letter
        print('Есть!')
        for i in range(len(word)):
            if word[i] == letter:
                draw.penup()
                draw.goto(-100 + i * 40, -150)
                draw.write(letter.upper(), align='center', font=('Arial', 30, 'normal'))
    else:
        wrong += letter
        print('Нет!')
        if not parts:
            print(f"Вы проиграли! Слово: {word}")
            break
        draw_body_part(parts[0])
        parts = parts[1:]
        print(f'Осталось: {len(parts)}')

input()
