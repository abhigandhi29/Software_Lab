from tkinter import *
import tkinter.font as tkFont

class InputField(Frame):
    def __init__(self, parent, text):
        Frame.__init__(self, parent)
        self.text = text
        self.font = tkFont.Font(family="Helvetica",size=12,weight="bold")
        self.expression = Entry(self,font=self.font) 
        self.initUI()

    def initUI(self):
        label_expression = Label(self, text=self.text,font=self.font)
        label_expression.pack(side=LEFT)
        self.expression.insert(0, "")
        self.expression.pack(fill=BOTH)

    def getInput(self):
        return self.expression.get()
