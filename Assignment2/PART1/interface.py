import tkinter as tk
import tkinter.font as tkFont
from matplotlib.figure import Figure
from matplotlib.backends.backend_tkagg import (FigureCanvasTkAgg, NavigationToolbar2Tk)
from InputFrame import *
from OutputFrame import *


class Interface:

    def __init__(self):
        self.root = tk.Tk()
        self.root.title('Range Plotter')
        self.root.geometry("700x700")
        self.fields = dict()
        self.all_points = []

        self.var = StringVar()
        self.var.set("Range Plotter")
        self.frameup = Frame(self.root, bg="blue", height="80")
        self.frameup.pack(fill=tk.X)
        self.title_font = tkFont.Font(family="Helvetica",size=32,weight="bold")
        self.title=Label(self.frameup,font=self.title_font,textvariable=self.var,bg="blue")
        self.title.pack(side=TOP)
        
        self.framel = Frame(self.root, bg="black", height="5")
        self.framel.pack(fill=tk.X,pady=(0,10))

        self.frame_top = Frame(self.root)
        self.frame_top.pack(fill=tk.X)

        self.input_frame = InputFrame(self.frame_top)
        self.input_frame.config()
        self.input_frame.pack(side=LEFT,expand=True,fill=tk.BOTH)

        #self.framer = Frame(self.frame_top, bg="red", width="100", height="300")
        #self.framer.pack(side=LEFT,expand=True,fill=tk.BOTH)

        self.buttonFrame = Frame(master=self.root,relief=tk.RAISED,borderwidth=5)
        self.buttonFrame.pack(pady=20)
        self.button = Button(self.buttonFrame, text="Submit", bg="white", fg="black", pady=5, padx=5, command=self.getFields)
        self.button.pack()

        self.frame_out = Frame(self.root)
        self.frame_out.pack(fill=BOTH,expand=1)

        self.output_frame = OutputFrame(self.frame_out)
        self.output_frame.pack(side=LEFT,expand=True,fill=BOTH,padx=20,pady=20)

        self.plot = Frame(self.frame_out, width=200, height=200)
        self.plot.pack(side=RIGHT,expand=True,fill=tk.BOTH)




    def run(self):
        self.root.mainloop()

    def getFields(self):
        self.fields = self.input_frame.getInputFields()
        self.getPoints()

    def plotexp(self):
        for widget in self.plot.winfo_children():
            widget.destroy()
        fig = Figure(figsize=(3, 3), dpi = 100)
        variable = self.fields["variable"]
        expression_new = self.fields["expression"].replace(variable, "x")
        y = [eval(expression_new) for x in range(eval(self.fields["left"]), eval(self.fields["right"]))]
        plot1 = fig.add_subplot(111)
        plot1.plot(y)

        canvas = FigureCanvasTkAgg(fig, master = self.plot)
        canvas.draw()
        canvas.get_tk_widget().pack()

        toolbar = NavigationToolbar2Tk(canvas, self.plot)
        toolbar.update()

        canvas.get_tk_widget().pack()



    def getPoints(self):
        if self.fields["variable"] and self.fields["expression"] and self.fields["left"] and self.fields["right"]:
            self.all_points.clear()
            for i in range(eval(self.fields["left"]), eval(self.fields["right"])+1):
                variable = self.fields["variable"]
                expression_new = self.fields["expression"].replace(variable, str(i))
                result = eval(expression_new)
                self.all_points.append((i, result))
            #print(self.all_points)
            self.output_frame.updateText(self.all_points, self.fields["variable"])
            self.plotexp()

        else:
            print("Form not filled completely")


