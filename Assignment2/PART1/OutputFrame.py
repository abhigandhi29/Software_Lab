from tkinter import *


class OutputFrame(Frame):
    def __init__(self, parent):
        Frame.__init__(self, parent)

        self.outputText = Text(self, bg="white", fg="black", width="30",selectborderwidth="3")
        self.outputText.pack(expand=1,fill=BOTH)

    def updateText(self, all_points, variable):
        result = "Values of expression for integers in the given range: \n"
        for i in all_points:
            result += variable + " = " + str(i[0]) + ", Value of expression is: " + str(i[1]) + "\n"

        self.outputText.delete("1.0", END)
        self.outputText.insert("1.0", result)
