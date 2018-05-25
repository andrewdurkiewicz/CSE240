package testingPanel;

import java.awt.Dimension;

import javax.swing.JFrame;
import javax.swing.JLayeredPane;
import javax.swing.JPanel;

import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import testingPanel.OvalLabel;

public class TestPanel {

	
	public static void main(String[] args) {

		// TODO Auto-generated method stub
		JFrame f = new JFrame();
		f.setSize(new Dimension(500,500));
		f.setVisible(true);
		
		JPanel p1 = new JPanel();
		p1.setSize(new Dimension(500, 500));
		p1.setBackground(Color.RED);
		p1.setOpaque(true);
		
		MouseMotionListener listener = new MouseMotionListener() {
			
			@Override
			public void mouseMoved(MouseEvent e) {
				// TODO Auto-generated method stub
				
			}
			
			@Override
			public void mouseDragged(MouseEvent e) {
				System.out.println(e.getX() + " , " + e.getY());
				
			}
		};
		p1.addMouseMotionListener(listener);
		
		 OvalLabel oval = new OvalLabel();
		 TriLabel triangle = new TriLabel();
		 RectLabel rectangle = new RectLabel();
		 StarLabel star = new StarLabel();
		 DiamondLabel diamond = new DiamondLabel();
		 oval.setVisible(true);
		//p1.setOpaque(true);
		JPanel p2 = new JPanel();
		p2.setSize(new Dimension(500, 100));
		p2.setBackground(Color.YELLOW);
		p2.setOpaque(true);
		//p2.setOpaque(true);
		
		JLayeredPane lPane = new JLayeredPane();
		f.add(lPane, BorderLayout.CENTER);
		lPane.setBounds(0, 0, 500, 500);
		lPane.add(p1, new Integer(0),0);
		lPane.add(p2, new Integer(1),0);
		Rectangle box= new Rectangle(5,10,20,30);
        System.out.println(box);
		//f.pack();

		
		
	
		
		
		
		
		

	}
	class RedSquare{
		 
	    private int xPos = 50;
	    private int yPos = 50;
	    private int width = 20;
	    private int height = 20;
	 
	    public void setX(int xPos){ 
	        this.xPos = xPos;
	    }
	 
	    public int getX(){
	        return xPos;
	    }
	 
	    public void setY(int yPos){
	        this.yPos = yPos;
	    }
	 
	    public int getY(){
	        return yPos;
	    }
	 
	    public int getWidth(){
	        return width;
	    } 
	 
	    public int getHeight(){
	        return height;
	    }
	 
	    public void paintSquare(Graphics g){
	        g.setColor(Color.RED);
	        g.fillRect(xPos,yPos,width,height);
	        g.setColor(Color.BLACK);
	        g.drawRect(xPos,yPos,width,height);  
	    }

}
}
