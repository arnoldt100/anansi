# TypeErasure Inheritance {#TypeErasureInheritance}

TypeErasure inheritance, as explained by Iglberger [1],

> Provides a value based, non-intrusive value based abstraction for an extendable
> set of unrelated  potential non-polymorphic types with the same semantic behavior. (p. 301)

The TypeErasure UML diagram is depicted below.

![UMLTypeErasureInheritance](TypeErasure.jpg)

We can group  the TypeErasure design pattern into 3 levels. The high level consists of the classes
ShapeConcept and OwningShapeModel. The middle level consists of the class Shape, and the low level
consists of the concrete classes Circle and Square.

The high level provides the semantic requirements for all shape types. For example, one can require
all shapes to provide a draw functionality. The class ShapeConcept is the base class that defines
the Shapes semantic requirements. Note that in ShapeConcept the abstract virtual method draw sets
the draw semantic.  The OwningShapeModel is a templated class whose template parameters are of
concrete shape types 

    template <typename T> 
    class OwningShapeModel<T>;

and OwningShapeModel constructor takes a concrete
shape, Circle, Square, ..., that is used to initialize the data member
OwningShapeModel::concreteShape_. 

    template <typename T>
    explcit OwningShapeModel<T>::OwningShapeModel( T & aConcreteShape) :
    concreteShape_{aConcreteShape};

OwningShapeModel must also implement the all virtual functions of
ShapeConcept. The method OwningShapeModel::draw()

    OwningShapeModel::draw() const override
    {
        shape_.draw_shape(shape_);
    }


The middle level class Shape wraps and transforms the high level hierarchy to value semantics and
a TypeErasure. Note that only Shape's constructor is templated on a concrete shape

    template<typename T>
    Shape::Shape(T && aConcreteShape) :
    valuePtr_(new ShapeModel<ShapeConcept>(std::forward<T>(aConcreteShape)));

where the concrete shape is wrapped in Shape::valuePtr_ 

    std::unique_ptr<ShapeConcept> Shape::valuePtr_;

---
[1] Iglberger, K. (2022). C++ Software Design. (First Edition).  O'Reilly Media. ISBN: 9781098113162.
