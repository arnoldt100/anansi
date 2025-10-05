# Anansi Naming Convention {#AnansiNamingConvention}


## File names
Stud text

## Classes 

### Class Names
In general, all class names will follow the upper camel case
convention, and should be nouns or noun phrases - not verbs. 
Some examples are `ReceiverInterface` and `GenericReceiverFactory`.

### Class Public, Protected and Privates Members
To aid in distinguishing public and private class members,
all public class members will not have a trailing underscore, and 
all protected and private class members will have a trailing underscore. 

    Class Circle : public Shape
    {
        public: 
            void move();
            double getArea() const;

        private:
            double radius_;
            void changeCircleCenter_();
    }; 

### Function Parameter Names
