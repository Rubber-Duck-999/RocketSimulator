'''
Created on 19 Jan 2019

@author: simon
'''


from tkinter import *
window = Tk()
window.title("Welcome to LikeGeeks app")
#
lbl = Label(window, text="Hello")
lbl.grid(column=0, row=0)
#
txt = Entry(window,width=10)
txt.grid(column=1, row=0)
#
def clicked():
    res = "Welcome to " + txt.get()
    lbl.configure(text= res)
btn = Button(window, text="Click Me", bg="orange", fg="red", command=clicked)
btn.grid(column=2, row=0)
#
window.geometry('350x200')
window.mainloop()