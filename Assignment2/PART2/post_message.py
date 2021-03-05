import tkinter.filedialog
import tkinter as tk
from tkinter import *
import tkinter.font as tkFont
from PIL import ImageTk, Image

class post:

    def __init__(self,user,data_usr,data_grp):
        self.root = Toplevel()
        self.root.title('Display Contacts')
        self.root.geometry("700x700")
        self.file=open("message.txt","a")

        
        self.usr = user
        self.data_user=data_usr
        self.data_grp = data_grp

        self.var = StringVar()
        self.var.set("Post to contact")
        self.frameup = Frame(self.root, bg="blue", height="80")
        self.frameup.pack(fill=tk.X)
        self.title_font = tkFont.Font(family="Helvetica",size=32,weight="bold")
        self.title=Label(self.frameup,font=self.title_font,text="Post to Contact",bg="blue")
        self.title.pack(side=TOP)
        

        self.framel = Frame(self.root, bg="black", height="5")
        self.framel.pack(fill=tk.X,pady=(0,10))

        self.frame_top = Frame(self.root)
        self.frame_top.pack(fill=tk.X)

        self.font = tkFont.Font(family="Helvetica",size=16,weight="bold")

        users=[]
        for data in user.contacts:
            users.append(data)
        if len(users)!=0:
            self.current_usr = users[0]
            
        
            variable = StringVar(self.root)
            variable.set(users[0])
            w=OptionMenu(self.frame_top,variable, *users,command=self.changeuser)
            w.config(font=self.font)
            w.pack()


            self.text1 = "Enter Message"
            label_expression = Label(self.frame_top, text=self.text1,font=self.font)
            label_expression.pack(side=LEFT)
            self.expression = Entry(self.frame_top,font=self.font) 
            self.expression.insert(0, "")
            self.expression.pack(fill=BOTH)

            self.buttonFrame1 = Frame(master=self.root,relief=tk.RAISED,borderwidth=5)
            self.buttonFrame1.pack(pady=20)
            self.button1 = Button(self.buttonFrame1, text="Post Message", bg="white", fg="black", pady=5, padx=5, command=self.message_usr,font=self.font)
            self.button1.pack()
            self.button2 = Button(self.buttonFrame1, text="Post Image", bg="white", fg="black", pady=5, padx=5, command=self.image_usr,font=self.font)
            self.button2.pack()

        self.var1 = StringVar()
        self.var1.set("Post to group")
        self.frameup1 = Frame(self.root, bg="blue", height="80")
        self.frameup1.pack(fill=tk.X)
        self.title_font1 = tkFont.Font(family="Helvetica",size=32,weight="bold")
        self.title1=Label(self.frameup1,font=self.title_font,text="Post to Group",bg="blue")
        self.title1.pack(side=TOP)        

        self.framel1 = Frame(self.root, bg="black", height="5")
        self.framel1.pack(fill=tk.X,pady=(0,10))

        self.frame_top1 = Frame(self.root)
        self.frame_top1.pack(fill=tk.X)

        self.font = tkFont.Font(family="Helvetica",size=16,weight="bold")

        grp=[]
        for data in data_grp:
            if self.check_member(data,user):
                grp.append(data.id)
        if len(grp)!=0:
            self.current_grp = grp[0]
            variable1 = StringVar(self.root)
            variable1.set(grp[0])
            w1=OptionMenu(self.frame_top1,variable1, *grp,command=self.changegrp)
            w1.config(font=self.font)
            w1.pack()


            label_expression1 = Label(self.frame_top1, text=self.text1,font=self.font)
            label_expression1.pack(side=LEFT)
            self.expression1 = Entry(self.frame_top1,font=self.font) 
            self.expression1.insert(0, "")
            self.expression1.pack(fill=BOTH)

            self.buttonFrame2 = Frame(master=self.root,relief=tk.RAISED,borderwidth=5)
            self.buttonFrame2.pack(pady=20)
            self.button3 = Button(self.buttonFrame2, text="Post Message", bg="white", fg="black", pady=5, padx=5, command=self.message_grp,font=self.font)
            self.button3.pack()
            self.button4 = Button(self.buttonFrame2, text="Post Image", bg="white", fg="black", pady=5, padx=5, command=self.image_grp,font=self.font)
            self.button4.pack() 

        
        
        #self.text = Text(self.frame_top,bg="white",fg="black",font=self.font,selectborderwidth="3")

        #self.message=user.id+" is in contact with: "+"\n"
        #for i in user.contact:
        #    self.message+= i+"\n"
        #self.text.insert("1.0",self.message)

    def changeuser(self,new):
        self.current_usr = new

    def changegrp(self,new):
        self.current_grp = new

    def message_usr(self):
        message = self.expression.get()
        self.expression.delete(0,END)
        for usr in self.data_user:
            if self.current_usr == usr.id:
                usr.new_message("text",self.usr,message)
                self.file.write(self.usr.id+" Sended "+message+" to "+usr.id+"\n")
                return


    def image_usr(self):
        photobox=tk.filedialog.askopenfilename(title='open')
        #print(str(photobox))
        for usr in self.data_user:
            if self.current_usr == usr.id:
                usr.new_message("image",self.usr,photobox)
                self.file.write(self.usr.id+" Sended "+str(photobox)+" to "+usr.id+"\n")
                return

    def message_grp(self):
        message = self.expression1.get()
        self.expression1.delete(0,END)
        for usr in self.data_grp:
            if self.current_grp == usr.id:
                usr.new_message("text",self.usr,message)
                self.file.write(self.usr.id+" Sended "+message+" to "+usr.id+"\n")
                return


    def image_grp(self):
        photobox=tk.filedialog.askopenfilename(title='open')
        for usr in self.data_grp:
            if self.current_grp == usr.id:
                usr.new_message("image",self.usr,photobox)
                self.file.write(self.usr.id+" Sended "+str(photobox)+" to "+usr.id+"\n")
                return



    def run(self):
        self.root.mainloop()

    def check_member(self,data_grp,usr):
        for i in data_grp.members:
            if  usr.id in i:
                return True
        
        return False