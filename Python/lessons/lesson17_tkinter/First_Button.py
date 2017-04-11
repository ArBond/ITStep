from tkinter import *

root = Tk()
root.title("New Window!")
root.geometry("500x500")

app = Frame(root)
app.grid()

bttn1 = Button(app, text = 'I do nothing!')
bttn1.grid()

bttn2 = Button(app)
bttn2.grid()
bttn2.configure(text = 'I am too!')

bttn3 = Button(app)
bttn3.grid()
bttn3['text'] = 'And I!'

root.mainloop()
