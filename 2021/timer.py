import tkinter as tk
import platform

window=tk.Tk()
window.title("Timer")

label1 = tk.Label(window, text = "0", font = "Times 25")
id = 0

def input_number1():
    if id == 0:
        if label1.cget("text") == "0":
            label1.configure(text = "1")
        else:
            label1.configure(text = label1.cget("text")+"1")
def input_number2():
    if id == 0:
        if label1.cget("text") == "0":
            label1.configure(text = "2")
        else:
            label1.configure(text = label1.cget("text")+"2")
def input_number3():
    if id == 0:
        if label1.cget("text") == "0":
            label1.configure(text = "3")
        else:
            label1.configure(text = label1.cget("text")+"3")
def input_number4():
    if id == 0:
        if label1.cget("text") == "0":
            label1.configure(text = "4")
        else:
            label1.configure(text = label1.cget("text")+"4")
def input_number5():
    if id == 0:
        if label1.cget("text") == "0":
            label1.configure(text = "5")
        else:
            label1.configure(text = label1.cget("text")+"5")
def input_number6():
    if id == 0:
        if label1.cget("text") == "0":
            label1.configure(text = "6")
        else:
            label1.configure(text = label1.cget("text")+"6")
def input_number7():
    if id == 0:
        if label1.cget("text") == "0":
            label1.configure(text = "7")
        else:
            label1.configure(text = label1.cget("text")+"7")
def input_number8():
    if id == 0:
        if label1.cget("text") == "0":
            label1.configure(text = "8")
        else:
            label1.configure(text = label1.cget("text")+"8")
def input_number9():
    if id == 0:
        if label1.cget("text") == "0":
            label1.configure(text = "9")
        else:
            label1.configure(text = label1.cget("text")+"9")
def input_number0():
    if id == 0:
        if label1.cget("text") == "0":
            label1.configure(text = "0")
        else:
            label1.configure(text = label1.cget("text")+"0")

def up_number():
    if id == 0:
        window.after(1000,after_up_number)

def after_up_number():
    global id
    i = int(label1.cget("text"))
    i += 1
    label1.configure(text = str(i))
    id = window.after(1000,after_up_number)

def down_number():
    if id == 0:
        window.after(1000,after_down_number)

def after_down_number():
    global id
    i = int(label1.cget("text"))
    if i > 0:
        i -= 1
        label1.configure(text = str(i))
        id = window.after(1000,after_down_number)
    else:
        if id != 0:
            if platform.system() == "Windows":
                def beep(freq,dur):
                    import winsound
                    winsound.Beep(freq, dur)
                for i in range(5):
                    for i in range(3):
                        beep(2000,100)
                    beep(37,300)
                            
            else:
                import os
                beep = lambda x: os.system("echo -n '\a';sleep 0.5;" * x)
                for i in range(5):
                    beep(3)
        id = 0
        
def stop_reset():
    global id
    if id == 0:
        label1.configure(text = "0")
    else:
        window.after_cancel(id)
        id = 0
        
button1 = tk.Button(window, text = "1", width = 10, height = 5, command = input_number1)
button2 = tk.Button(window, text = "2", width = 10, height = 5, command = input_number2)
button3 = tk.Button(window, text = "3", width = 10, height = 5, command = input_number3)
button4 = tk.Button(window, text = "4", width = 10, height = 5, command = input_number4)
button5 = tk.Button(window, text = "5", width = 10, height = 5, command = input_number5)
button6 = tk.Button(window, text = "6", width = 10, height = 5, command = input_number6)
button7 = tk.Button(window, text = "7", width = 10, height = 5, command = input_number7)
button8 = tk.Button(window, text = "8", width = 10, height = 5, command = input_number8)
button9 = tk.Button(window, text = "9", width = 10, height = 5, command = input_number9)
button0 = tk.Button(window, text = "0", width = 10, height = 5, command = input_number0)
button_up = tk.Button(window, text = "up", width = 10, height = 5, command = up_number)
button_down = tk.Button(window, text = "down", width = 10, height = 5, command = down_number)
button_stop = tk.Button(window, text = "stop\nreset", width = 30, height = 5, command = stop_reset)

label1.grid(row = 0, columnspan = 3)
button1.grid(row = 2, column = 0)
button2.grid(row = 2, column = 1)
button3.grid(row = 2, column = 2)
button4.grid(row = 3, column = 0)
button5.grid(row = 3, column = 1)
button6.grid(row = 3, column = 2)
button7.grid(row = 4, column = 0)
button8.grid(row = 4, column = 1)
button9.grid(row = 4, column = 2)
button0.grid(row = 5, column = 1)
button_up.grid(row = 5, column = 0)
button_down.grid(row = 5, column = 2)
button_stop.grid(row = 6, columnspan = 3)

window.mainloop()