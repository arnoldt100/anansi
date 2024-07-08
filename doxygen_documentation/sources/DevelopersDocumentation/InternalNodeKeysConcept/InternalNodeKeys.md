#  Internal Node Keys {#InternalNodeKeysConcept}

## Internal Node Keys Semantics

The class `InternalNodeKeysConcept` is a [type erasure](#TypeErasureInheritance) for it wraps
concrete objects which then loses their type identity. The wrapped concrete objects must implement the
semantics of the `InternalNodeKeysConcept` or bad program behavior will occur.

The wrapped concrete objects must implement the following free functions:

    std::string get_internal_node_key(ConcreteInternalNodeKey_Type const & concrete_object,std::string external_key)

## Internal Node Keys Design Considerations

Each Anansi input file that has [CommandFiles](#CommandFilesConcept) semantics has a corresponding
external node key class whose primary responsibility is to return the appropriate key for a
desired value. The external node key class maps a general internal key to a specific 
external key for the input file type. For example, consider an xml file, *PointAtoms.xml*, that has the node

    <data>
        <Number_of_point_atoms> 10 </Number_of_point_atoms>
    </data>

The program has a general internal key "number_of_atoms" in which the external node key class maps
to xml key `<Number_of_point_atoms>`. The general internal keys are stored in "internal node key
classes". For our above specific example let's call the internal node key class
'InternalAtomNodeKeys' and the external node key class `ExternalPointAtomsNodeKeys`. This design of
having "internal node key classes" and "external node key classes" breaks the dependency between the
internal and external keys. Consider the following scenario where in file *PointAtoms.xml* the node
is changed to

    <data>
        <Number_point_atoms> 10 </Number_point_atoms>
    </data>

Only the class `ExternalPointAtomsNodeKeys` needs to be modified to reflect the new xml tag
`<Number_point_atoms>`.






