import tkinter.filedialog
import tkinter as tk
from tkinter import *
import tkinter.font as tkFont
from PIL import ImageTk, Image

class incoming:

    def __init__(self,user,data_grp):
        self.root = Toplevel()
        self.root.title('Recieved')
        self.root.geometry("700x700")

        self.var = StringVar()
        self.var.set('Recieved')
        self.frameup = Frame(self.root, bg="blue", height="80")
        self.frameup.pack(fill=tk.X)
        self.title_font = tkFont.Font(family="Helvetica",size=32,weight="bold")
        self.title=Label(self.frameup,font=self.title_font,text="Recieved",bg="blue")
        self.title.pack(side=TOP)
        self.frameup.update()
        

        self.framel = Frame(self.root, bg="black", height="5")
        self.framel.pack(fill=tk.X,pady=(0,10))

        self.frame_top = Frame(self.root)
        self.frame_top.pack(fill=tk.X)

        self.font = tkFont.Font(family="Helvetica",size=16,weight="bold")
        #self.message = StringVar()
        self.message=user.id+" has received: "

        self.label = Label(self.frame_top,bg="white",fg="black",text=self.message,font=self.font)
        self.label.pack()

        for i in user.message:
            if i[0]=='image':
                self.image(i)
            else : 
                self.text(i)

        for i in data_grp:
            if self.check_member(i,user):
                self.message=("Message posted in "+i.id+":\n")
                label = Label(self.frame_top,bg="white",fg="black",text=self.message,font=self.font)
                label.pack()

                for j in i.message:
                    if j[0]=='image':
                        self.image(j)
                    else : 
                        self.text(j)


    def image(self,i):
        self.message="Image sended by "+i[1].id+":"
        label = Label(self.frame_top,bg="white",fg="black",text=self.message,font=self.font)
        label.pack()
        img = Image.open(i[2])
        img = img.resize((250, 250), Image.ANTIALIAS)
        img = ImageTk.PhotoImage(img)
        panel = Label(self.frame_top, image=img)
        panel.image = img
        panel.pack()


    def text(self,i):
        self.message="Message sended by "+i[1].id+" is "+i[2]+"\n"
        label = Label(self.frame_top,bg="white",fg="black",text=self.message,font=self.font)
        label.pack()

    def check_member(self,data_grp,usr):
        for i in data_grp.members:
            if  usr.id in i:
                return True
        return False

    def run(self):
        self.root.mainloop()