.. index:: single: conventions; coding

Coding Conventions
==================

.. index:: conventions; header files

Header Files
------------

.. code-block:: c

   /* This is free and unencumbered software released into the public domain. */
   
   #ifndef CPR_WIDGET_H
   #define CPR_WIDGET_H
   
   /**
    * @file
    *
    * Module description goes here.
    */
   
   #ifdef __cplusplus
   extern "C" {
   #endif
   
   #include <stdbool.h> /* for bool */
   
   /**
    * Function description goes here.
    */
   bool cpr_widget_supported(const char* widget_type);
   
   #ifdef __cplusplus
   } /* extern "C" */
   #endif
   
   #endif /* CPR_WIDGET_H */
