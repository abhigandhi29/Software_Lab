from interface import *

class manager:
    def __init__(self,data_user,data_grp):
        self.users=data_user
        self.grp=data_grp

    def run(self):
        I=Interface(self.users,self.grp)
        I.run()

