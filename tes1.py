import turtle

t = turtle.Turtle()
t.speed(3)
turtle.bgcolor("skyblue")

def draw_circle(r):
    t.begin_fill()
    t.circle(r)
    t.end_fill()

t.penup()
t.goto(0, -100)
t.pendown()

t.color("black", "brown")
draw_circle(100)

t.penup()
t.goto(-70, 80)
t.pendown()
draw_circle(40)

t.penup()
t.goto(70, 80)
t.pendown()
draw_circle(40)

t.penup()
t.goto(-35, 20)
t.pendown()
t.color("black")
draw_circle(10)

t.penup()
t.goto(35, 20)
t.pendown()
draw_circle(10)

t.penup()
t.goto(0, -20)
t.pendown()
draw_circle(15)

turtle.done()
