from tkinter import *
from InputField import *


class InputFrame(Frame):
    def __init__(self, parent):
        Frame.__init__(self, parent)

        self.variable_frame = InputField(self, "Enter the variable: ")
        self.variable_frame.pack(fill=X, padx=5, pady=5)

        self.expression_frame = InputField(self, "Enter the expression for variable: ")
        self.expression_frame.pack(fill=X, padx=5, pady=5)

        self.frame_left = InputField(self, "Enter the left end of range: ")
        self.frame_left.pack(fill=X, padx=5, pady=5)

        self.frame_right = InputField(self, "Enter the right end of the range: ")
        self.frame_right.pack(fill=X, padx=5, pady=5)

    def getInputFields(self):
        fields = dict()
        fields["variable"] = self.variable_frame.getInput()
        fields["expression"] = self.expression_frame.getInput()
        fields["left"] = self.frame_left.getInput()
        fields["right"] = self.frame_right.getInput()
        return fields
