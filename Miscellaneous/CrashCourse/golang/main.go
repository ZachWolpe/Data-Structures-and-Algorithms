
// crash course: https://www.youtube.com/watch?v=Yo2xmii7TbA

package main

import (
	"fmt"
	"strconv"
	"reflect"
)


// Go types ----------------------------------------------**
var myBoolean bool   = true
var myInteger int    = 123
var myString  string = "woah!"

// declare with default values, on one line 
var int1, int2, int3 int

// different bit sizes
var MyInt8 int8
var MyInt16 int16
var MyInt32 int32

var myUnit uint // unsigned integer is always positive

var myRume rune // alias for int32, represents a unicode code point
var myByte byte // alias for uint8

// const: cannot be changed (immutable)
const myConst = "Test"
const MyIntConst int = 123
const myFloatConst float32 = 1.432
// Go types ----------------------------------------------**



// abstract a function -----------------------------------**
func WhatDoesMyPetSay(myPets map[string]Pet) int {
	numPets := 0
	for petName, petData := range myPets {
		switch petData.Age {
			case 1: fmt.Println(petName, "is a young", petData.Name)
			case 2: fmt.Println(petName, "is an old", petData.Name)
			default: fmt.Println(petName, "is a very old", petData.Name)
	}
}

// Example usage -----------------------------------------**
func main() {
	fmt.Println("Hello World!")



	// basic numerical operations are available cross type
	MyInt8 = 10
	MyInt8 = MyInt8 * 5
	MyInt8 += 1
	myBoolean = MyInt8 > 15

	// string concatenation
	myString = "Hello" + " " + "World!"
	myWorldString := "Hello" + " " + "World!"
	fmt.Println(myWorldString)

	myString = strconv.Itoa(myInteger)
	int1, _  = strconv.Atoi(myString)
	myBoolean, _ = strconv.ParseBool("true")
	fmt.Println(reflect.TypeOf(myBoolean))

	// Go types ----------------------------------------------**

	// Composite Types ---------------------------------------**
	// arrays
	var ExampleArray [5]int
	exampleArr := [3]int{1,2,3}
	fmt.Println(ExampleArray[0])
	fmt.Println(exampleArr[0])

	// slices: variable length, can be resized
	// var exampleSlice []int
	exampleSli := []int{1,2,3}
	exampleSlice := []string{"hello", "my", "awesome", "developer"}
	fmt.Println(exampleSlice[0])
	fmt.Println(exampleSli[0])

	exampleArr[0] = 21 // change value, variable already declared.

	// append
	exampleSlice = append(exampleSlice, "friend")
	fmt.Println(exampleSlice)
	// Composite Types ---------------------------------------**


	// Maps --------------------------------------------------**
	// maps: (unorderd) key:value pairs
	myMap := map[string]int{"dog":4, "cat":5, "fish":2}
	fmt.Println(myMap["dog"])

	// add new key:value pair
	myMap["bird"] = 3
	fmt.Println(myMap)

	// delete key:value pair
	delete(myMap, "fish")
	myMap["cat"] = myMap["cat"] - 1
	// Maps --------------------------------------------------**

	// Structs -----------------------------------------------**
	// structs: collection of fields
	type Pet struct {
		Name string
		Age int
	}

	myPets := map[string]Pet{
		"dog": Pet{"Fido", 5},
		"cat": Pet{"Milo", 3},
		"bird": Pet{"Tweety", 1},
	}
	fmt.Println(myPets)
	// Structs -----------------------------------------------**
	
	// Control Flow ------------------------------------------**
	if myPets["dog"].Age >= 4 {
		fmt.Println("Old dog")
	} else {
		fmt.Println("Young dog")
	}

	// Switch
	switch myPets["dog"].Age {
		case 1: fmt.Println("Young dog")
		case 2: fmt.Println("Old dog")
		default: fmt.Println("Very old dog")
	}

	// For loop
	for i := 0; i < 5; i++ {
		fmt.Println(i)
	}

	// over a slice
	// for index, value := range slice {
	// 	fmt.Println(index, value)
	// }
	
	// over a map
	for key, value := range myMap {
		fmt.Println(key, value)
	}

	// over a map
	for petName, petData := range myPets {
		switch petData.Age {
			case 1: fmt.Println(petName, "is a young", petData.Name)
			case 2: fmt.Println(petName, "is an old", petData.Name)
			default: fmt.Println(petName, "is a very old", petData.Name)
	}
}

	petNum := WhatDoesMyPetSay(myPets)

}