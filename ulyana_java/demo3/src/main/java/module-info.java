module demo1.demo3 {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.controlsfx.controls;
    requires java.desktop;

    opens demo1.demo3 to javafx.fxml;
    exports demo1.demo3;
}