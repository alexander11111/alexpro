package ru.java.store;

import java.util.List;

public interface IStorage {
     classes getClassName(String name);
     List<classes> getAllClass();
     void close();
}
