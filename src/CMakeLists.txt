
set(EXECSOURCE
	main.cpp

	accQT.cpp
	accQT.h

	proto.h
	proto.cpp
	)

set(UISOURCE

	mainwindow.cpp
	mainwindow.h

	appfield.cpp
	appfield.h
	)

set(SOURCE ${EXECSOURCE} ${UISOURCE})

#message(${SOURCE})
add_executable(${PRNAME} ${SOURCE})

foreach (I IN LISTS REQUIRES)
	find_package(QT NAMES Qt6 Qt5      COMPONENTS ${I} REQUIRED)
	find_package(Qt${QT_VERSION_MAJOR} COMPONENTS ${I} REQUIRED)
	target_link_libraries(${PRNAME} PRIVATE Qt${QT_VERSION_MAJOR}::${I})
endforeach()
